/**
 * @file NumberOfEnclaves.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossible(int NR , int NC , vector<vector<int>>& grid , vector<vector<int>>& vis){
        int n = grid.size() , m = grid[0].size();
        if(NR >= 0 && NR < n && NC >= 0 && NC < m && vis[NR][NC] == 0 && grid[NR][NC] == 1){
            return true;
        }
        return false;
    }
private:
    vector<pair<int,int>> movements = {
        {1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}
    };
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m , 0));

        queue<pair<int,int>>q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
                    q.push({i , j});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;

            q.pop();
            for(int i = 0 ; i < n ; i++){
                int NR = x + movements[i].first;
                int NC = y + movements[i].second;

                if(isPossible(NR , NC , grid , vis)){
                    vis[NR][NC] = 1;
                    q.push({NR , NC});
                }
            }
        }
        
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};