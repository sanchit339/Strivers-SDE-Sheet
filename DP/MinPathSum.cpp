/**
 * @file MinPathSum.cpp
 * @author Striver
 * 
 * @brief for( i < 0 || j < 0 ) return INT_MAX so that it becomes infinite Path
 * 
 * @version 0.1
 * @date 2023-08-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int n , int m , vector<vector<int>>& grid , vector<vector<int>>& dp){
        if(n == 0 &&  m == 0) return grid[0][0];
        if(n < 0 || m < 0) return 1e9;

        if(dp[n][m] != -1) return dp[n][m];

        long long up = grid[n][m] + solve(n - 1 , m , grid , dp);
        long long left = grid[n][m] + solve(n , m - 1 , grid , dp);

        return dp[n][m] = min(up , left);
    } 
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n , vector<int>(m , -1));
        return solve(n - 1 , m - 1 , grid , dp);
    }
};

class Solution{
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n , vector<int>(m , -1));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else{
                    int up = grid[i][j];
                    if(i > 0) up += dp[i - 1][j];
                    else up += 1e9;

                    int left = grid[i][j];
                    if(j > 0) left += dp[i][j - 1];
                    else left += 1e9;

                    dp[i][j] = min(up , left);
                }
            }
        }
        return dp[n - 1][m - 1];
    } 
};



class Solution{
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> prev(m , -1);

        for(int i = 0 ; i < n ; i++){
            vector<int> curr(m , -1);
            for(int j = 0 ; j < m ; j++){
                if(i == 0 && j == 0) curr[j] = grid[i][j];
                else{
                    int up = grid[i][j];
                    if(i > 0) up += prev[j];
                    else up += 1e9;

                    int left = grid[i][j];
                    if(j > 0) left += prev[j - 1];
                    else left += 1e9;

                    curr[j] = min(up , left);
                }
            }
            prev = curr;
        }
        return prev[m - 1];
    } 
};