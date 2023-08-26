/**
 * @file 0_1_KnapSack.cpp
 * @author Striver 
 * 
 * @brief Theaf Problem
 * 
 * @version 0.1
 * @date 2023-08-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    int solve(int W , int wt[] , int val[] , int n , vector<vector<int>> &dp){
        if(n == 0){
            if(wt[0] <= W){
                return val[0];
            }
            else return 0;
        }

        if(dp[n][W] != -1)
            return dp[n][W];
        
        int notTake = solve(W , wt , val , n - 1 , dp);
        int take = INT_MIN;
        if(wt[n] <= W) take = val[n] + solve(W - wt[n] , wt , val , n - 1 , dp);

        return dp[n][W] = max(take , notTake);
    }
public:
    int knapSack(int W, int wt[], int val[], int n){
        vector<vector<int>> dp(n , vector<int>(W + 1 , -1));
        return solve(W , wt , val , n - 1 , dp);
    }
};


class Solution{
public:
    int knapSack(int W, int wt[], int val[], int n){
        vector<vector<int>> dp(n , vector<int>(W + 1 , 0));
        
        // base case
        for(int weight = wt[0] ; weight <= W ; weight++){ // at this will theaf
            dp[0][weight] = val[0]; // for all weight we can steal and get the val
        }

        for(int idx = 1 ; idx < n ; idx++){
            for(int weight = 0 ; weight <= W ; weight++){
                int notTake = dp[idx - 1][weight];
                int take = INT_MIN;
                if(wt[idx] <= weight) take = val[idx] + dp[idx - 1][weight - wt[idx]];

                dp[idx][weight] = max(notTake , take);
            }
        }
        return dp[n - 1][W];
    }
};