/**
 * @file NumberOfIsland.cpp
 * @author One And Only Luv :) 
 * 
 * @brief > 4 side dfs and mark them visited by '0'
 * 
 * @version 0.1
 * @date 2023-08-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // replace vis by setting it to zero
    void dfs(int i , int j , vector<vector<char>>& grid){
        int n = grid.size() , m = grid[0].size();
        if(i < 0 || j < 0) return; // invalid nodes eliminate
        if(i >= n || j >= m) return;
        if(grid[i][j] == '0') return;

        grid[i][j] = '0'; // mark visited , dfs all the other
        dfs(i+1 , j , grid);
        dfs(i-1 , j , grid);
        dfs(i , j+1 , grid);
        dfs(i , j-1 , grid);
        
        // if all 8 axis are connected
        dfs(i+1 , j + 1 , grid);
        dfs(i-1 , j + 1 , grid);
        dfs(i - 1 , j - 1 , grid);
        dfs(i + 1 , j-1 , grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        // dfs( 0 , 0  , grid)
        int n = grid.size() , m = grid[0].size();
        int count = 0;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(i , j ,grid);
                }
            }
        }
        return count;
    }
};