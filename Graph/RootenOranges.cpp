/**
 * @file RootenOranges.cpp
 * @author Luv
 * 
 * @brief > Standerd Question 
 *        > Find min / short 
 * 
 * @version 0.1
 * @date 2023-08-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(int NR , int NC , vector<vector<int>> grid , vector<vector<int>> vis , int n , int m){
        if(NR >= 0 && NR < n && NC >= 0 && NC < m && vis[NR][NC] == 0 && grid[NR][NC] == 1){
            return true;
        }
        return false;
    }
private:
    vector<pair<int,int>> movements = {
        { -1 , 0 } , 	//up
		{ 0 , 1 } , 	// right
		{ 1 , 0 } , 	// dowm
		{ 0 , -1 } 	    // left
    };
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        // MainTain Visited
        // vector<vector<int>> vis( n , vector<int>(m , 0));
        vector<vector<int>> vis(n , vector<int>(m , 0));
        queue<pair<pair<int,int> , int>> q; // ({x , y} , t)

        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(grid[i][j] == 2){
                    q.push({{i , j} , 0}); // initial start
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }

        int MinTime = 0;
       

        while (!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;

            int t = q.front().second;
            
            q.pop();

            MinTime = max(MinTime , t);

            for(int i = 0 ; i < 4 ; i++){ // check all sides
                int newRow = movements[i].first + x;
                int newCol = movements[i].second + y;

                if(check(newRow , newCol , grid , vis , n , m)){
                    q.push({{newRow , newCol} , t + 1});
                    vis[newRow][newCol] = 2;
                }
            }
        }
        // if No one Was Rotten return -1
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; ++j){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return MinTime;
    }
};