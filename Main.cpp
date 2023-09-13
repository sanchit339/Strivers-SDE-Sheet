/**
 * @file Main.cpp
 * @author ATCoder DP Contest
 * 
 * @brief DP 1 and 1 _ 1 step 
 * 
 * @version 0.1
 * @date 2023-08-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(string s){
        int n = stoi(s);
        for(int i = 2 ; i <= sqrt(n) ; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
public:
    int StringToInt(string v){
        int result = 0 ;
        for (char bit : v) {
            result = (result << 1) | (bit - '0');
        }
        return result;
    }
public: 
    void solve(int idx , string s , string temp , vector<string> &subSeq){
        int n = s.size();
        if(idx == n){
            subSeq.push_back(temp);
            return;  
        } 
        subSeq.push_back(temp);

        temp.push_back(s[idx]);
        solve(idx + 1 , s , temp , subSeq);
        temp.pop_back();
        solve(idx + 1, s , temp , subSeq);
    }
};

int main(){
    string s; cin >> s;
    int idx = 0;
    vector<string> subSeq;
    string temp;
    Solution ans;
    ans.solve(idx , s , temp , subSeq);

    // cout << stoi(s) << endl;
    int prime = INT_MIN;
    for(string str : subSeq){
        if(str.size()){
            if(ans.isPrime(str)){
                int result = 0;
                result = ans.StringToInt(str);
                prime = max(prime , result);
            }
        }
    }
    cout << prime << endl;
}

/*
1 
1 0 
1 0 1 
1 0 1 1 
1 0 1 
1 0 
1 0 1 
1 0 
1 
1 1 
1 1 1 
1 1 
1 
1 1 
1 

0 
0 1 
0 1 1 
0 1 
0 
0 1 
0 

1 
1 1 
1 

1
*/

/*
1 0 1 1 
1 0 1 
1 0 1 
1 0 
1 1 1 
1 1 
1 1 
1 
0 1 1 
0 1 
0 1 
0 
1 1 
1 
1
*/
/*
1 
1 0 
1 0 1 
1 0 1 1 
1 0 1 
1 0 
1 0 1 
1 0 
1 
1 1 
1 1 1 
1 1 
1 
1 1 
1 
0 
0 1 
0 1 1 
0 1 
0 
0 1 
0 
1 
1 1 
1 
1
*/