/**
 * @file coinChange1.cpp
 * @author Leetcode
 * @brief T / arr[0]
 * @version 0.1
 * @date 2023-08-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// count the elements
class Solution {
private:
    int solve(int n , int amount , vector<int>& coins , vector<vector<int>> &dp){
        if(n == 0){
            if(amount % coins[0] == 0) return amount / coins[0];
            else return 1e9; // unreachable
        }
        if(dp[n][amount] != -1)
            return dp[n][amount];
        
        int notTake = solve(n - 1 , amount , coins , dp);
        int take = INT_MAX;
        if(coins[n] <= amount) take = 1 + solve(n , amount - coins[n] , coins , dp);

        return dp[n][amount] = min(take , notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount + 1 , -1));
        int ans = solve(n - 1 , amount , coins , dp);
        if(ans >= 1e9) return -1;
        return ans;
    }   
};


class Solution{
public:
    int coinChange(vector<int>& coins, int amount){
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount + 1 , -1));
        
        for(int total = 0 ; total <= amount ; total++){
            if(total % coins[0] == 0) 
                dp[0][total] = total / coins[0];
            else dp[0][total] = 1e9;
        }

        for(int idx = 1 ; idx < n ; idx++){
            for(int total = 0 ; total <= amount ; total++){
                int notTake = dp[idx - 1][total];
                int take = 1e9;
                if(coins[idx] <= total) take = 1 + dp[idx][total - coins[idx]];

                dp[idx][total] = min(take , notTake);
            }
        }

        if(dp[n - 1][amount] >= 1e9)
            return -1;
        return dp[n - 1][amount];
    }
};