/**
 * @file MaxPathSum.cpp
 * @author Striver
 * 
 * @brief > Start from anywhere in first row And End at anywhere in last row
 * 
 * @version 0.1
 * @date 2023-08-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    int solve(int i , int j , vector<vector<int>>& Matrix , vector<vector<int>> &dp){
        if(i < 0 || j >= Matrix[0].size()) return -1e8; // as we are taking MAX of all
        if(i == 0) return Matrix[0][j];

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = Matrix[i][j] + solve(i - 1 , j , Matrix , dp);
        int left = Matrix[i][j] + solve(i - 1 , j - 1 , Matrix , dp);
        int right = Matrix[i][j] + solve(i - 1 , j + 1 , Matrix , dp);

        return dp[i][j] = max(up , max(right , left));
    }
public:
    int maximumPath(int N, vector<vector<int>> Matrix){ // N*N matrix
        vector<vector<int>> dp(N , vector<int>(N , -1));

        int maxi = -1e8;
        for(int j = 0 ; j < N ; j++){
            maxi = max(maxi , solve(N - 1 , j , Matrix , dp));
        }
        return maxi;
    }
};

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix){ // N*N matrix
        vector<vector<int>> dp(N , vector<int>(N , -1));

        for(int i = 0 ; i < N ; i++) dp[0][i] = Matrix[0][i]; // initilize from start

        for(int i = 1 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                int up = Matrix[i][j] + dp[i - 1][j];
                
                int left = Matrix[i][j];
                if(j - 1 > 0){
                    left += dp[i - 1][j - 1];
                } else left += -1e8;

                int right = Matrix[i][j];
                if(j + 1 < N) 
                    right += dp[i - 1][j + 1];
                else right += -1e8;

                dp[i][j] = max(up , max(left , right));
            }
        }

        int maxi = -1e8;
        for(int j = 0 ; j < N ; j++){
            maxi = max(maxi , dp[N - 1][j]);
        }
        return maxi;
    }
};
/*
    int up = Matrix[i][j] + dp[i - 1][j];
    int left = Matrix[i][j] + dp[i - 1][j - 1];
    int right = Matrix[i][j] + dp[i - 1][j + 1];
*/