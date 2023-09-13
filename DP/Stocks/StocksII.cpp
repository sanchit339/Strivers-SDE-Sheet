/**
 * @file StocksII.cpp
 * @author Striver
 * @brief > Buy = -price : sell +price (profit) 
 * @version 0.1
 * @date 2023-08-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(vector<int> &prices , int n , int idx , vector<vector<int>> &dp , int buy){
        if(n == idx)
            return 0; //  

        if(dp[idx][buy] != 1)
            dp[idx][buy];
        
        int profit = 0;
        
        if(buy){
            profit = max( -prices[idx] + solve(prices , n , idx + 1 , dp , 0) , solve(prices , n , idx + 1 , dp , 1));
        }
        else{
            profit = max(prices[idx] + solve(prices , n , idx + 1 , dp , 1) , solve(prices , n , idx + 1  , dp , 0));
        }

        return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() , idx = 0;
        vector<vector<int>>dp(n , vector<int>(2 , -1));
        return solve(prices , n , idx , dp , 1);
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() , idx = 0;
        vector<vector<int>>dp(n + 1 , vector<int>(2 , -1));

        dp[n][0] = dp[n][1] = 0; // as per base case

        for(int idx = n - 1 ; idx >= 0 ; --idx){
            for(int buy = 0 ; buy <= 1 ; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[idx] + dp[idx + 1][0] , dp[idx + 1][1]);
                }
                else{
                    profit = max(prices[idx] + dp[idx + 1][1] , dp[idx + 1][0]);
                }
                dp[idx][buy] = profit;
            }
        }
        return dp[0][1]; // assume we are ready to buy
    }
};