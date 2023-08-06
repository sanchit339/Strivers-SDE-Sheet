/*

logic :- 

*/

#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
    string finalString(string s) {
        string ans;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == 'i'){
                reverse(s.begin() , s.begin() + i);
            }
        }
        for(auto it : s){
            if(it != 'i') ans += it;
        }
        return ans;
    }
// };


int main(){
    string s = "poiinter";
    cout << finalString(s);
    int i = 065 , j = 65;
    printf("%d" "%d" , i , j);
}