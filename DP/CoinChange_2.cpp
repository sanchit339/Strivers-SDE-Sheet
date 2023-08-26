/**
 * @file CoinChnage.cpp
 * @author Striver
 * 
 * @brief > Base Case Target % ARR[0] == 0
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
    int solve(int idx , int amount , vector<int> &coins ,  vector<vector<int>> &dp){
        if(idx == 0){
            return (amount % coins[0] == 0);
        }

        if(dp[idx][amount] != -1)
            return dp[idx][amount];

        int notTake = solve(idx - 1 , amount , coins , dp);
        int take = 0;
        if(coins[idx] <= amount) take = solve(idx , amount - coins[idx] , coins , dp);

        return take + notTake; // return total count
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount + 1 , -1));
        return solve(n - 1 , amount , coins , dp);
    }
};

class Solution{
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount + 1 , 0)); // false true ( 0 / 1 )
        for(int total = 0 ; total <= amount ; total++){
            dp[0][total] = (total % coins[0] == 0);
        }

        for(int idx = 1 ; idx < n ; idx++){
            for(int total = 0 ; total <= amount ; total++){
                int notTake = dp[idx - 1][total];
                int take = 0;
                if(coins[idx] <= total){
                    take = dp[idx][total - coins[idx]];
                }

                dp[idx][total] = take + notTake;
            }
        }
        return dp[n - 1][amount];
    }
};


class Solution{
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount + 1 , 0) , curr (amount + 1 , 0);
        for(int total = 0 ; total <= amount ; total++){
            prev[total] = (total % coins[0] == 0);
        }

        for(int idx = 1 ; idx < n ; idx++){
            for(int total = 0 ; total <= amount ; total++){
                int notTake = prev[total];
                int take = 0;
                if(coins[idx] <= total){
                    take = curr[total - coins[idx]];
                }

                curr[total] = take + notTake;
            }
            prev = curr;
        }
        return prev[amount];
    }
};