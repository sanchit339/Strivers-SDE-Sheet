/**
 * @file RodCutting.cpp
 * @author Code Studio Solution
 * 
 * @brief > Same AS KnapSack
 * 
 * @version 0.1
 * @date 2023-08-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int idx , int n , vector<int>& cuts , vector<vector<int>> & dp){
        if(idx == 0){
            return n * cuts[0];
        }
        if(dp[idx][n] != -1)
            return dp[idx][n];
        
        int notTake = solve(idx - 1 , n , cuts , dp);
        int take = INT_MAX;
        int rodLength = idx + 1;
        if(idx <= n)
            take = cuts[idx] + solve(idx , n - rodLength , cuts , dp);

        return dp[idx][n] = min(take , notTake);
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int idx = cuts.size();
        vector<vector<int>> dp(idx , vector<int>(n + 1 , -1));
        return solve(idx - 1 , n , cuts , dp);
    }
};