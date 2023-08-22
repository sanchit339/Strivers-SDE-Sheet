/**
 * @file UniquePatternObstra.cpp
 * @author Atcoder
 * 
 * @brief Return -0 arr[i][j] = -1;
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
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size(); 
        vector<vector<int>> dp(n , vector<int>(m , -1));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(obstacleGrid[i][j]) dp[i][j] = 0;
                else if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int up = 0 , left = 0;
                    if(i > 0)
                        up = dp[i - 1][j];
                    
                    if(j > 0)
                        left = dp[i][j - 1];
                    
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};