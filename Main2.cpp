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
    void solve(int n , int x ,  vector<int> g[] , vector<int> &temp , vector<int> &vis){
        temp.push_back(x);
        vis[x] = 1;
        for(auto child : g[x]){
            if(vis[child]) continue;
            solve(n , child , g , temp , vis);
        }
    }
};

int main(){
    int n; cin >> n;
    vector<int> g[n + 1];
    for(int i = 0 ; i < n ; i++){
        int x , y ;
        cin >> x >> y;
        g[x].push_back(y);
    }

    int maxi = INT_MIN , ret = INT_MIN;
    
    Solution ans;

    for(int i = 1 ; i <=  n ; i++){
        vector<int> temp;
        vector<int> vis(n + 1 , 0);
        ans.solve(n , i , g , temp , vis);
        int s = temp.size();
        if(s > maxi){
            maxi = temp.size();
            if(maxi > 0){
                ret = temp[0];
            }
        }
    }
    cout << ret << endl;
}