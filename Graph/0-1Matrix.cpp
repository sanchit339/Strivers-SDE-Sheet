/**
 * @file 0-1Matrix.cpp
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
    bool isPossible(int newRow , int newCol , int n , int m , vector<vector<int>> &vis){
        if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol]){
            return true;
        }
        return false;
    }
private:
    vector<pair<int,int >> movements = {
        {0 , 1} ,
        {1 , 0} ,
        {-1 , 0} ,
        {0 , -1}
    };
public:
	vector<vector<int>>nearest(vector<vector<int>>grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m ,0));
        vector<vector<int>> dis(n , vector<int>(m ,0));

        queue<pair<pair<int,int> , int >> q;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; ++j){
                if(grid[i][j] == 1){
                    q.push({{ i , j } , 0});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;

            q.pop();
            dis[row][col] = dist;

            for(int i = 0 ; i < 4 ; i++){
                int newRow = row + movements[i].first;
                int newCol = col + movements[i].second;

                if(isPossible(newRow , newCol , n , m , vis)){
                    q.push({{newRow , newCol} , dist + 1});
                    vis[newRow][newCol] = 1;
                }
            }
        }
        return dis;
	}
};
