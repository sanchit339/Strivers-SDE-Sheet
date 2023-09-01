/**
 * @file stcoks-III.cpp
 * @author Leetcode
 * @brief 
 * @version 0.1
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int idx , int cnt , int buy , int n , vector<int> &prices , vector<vector<vector<int>>> &dp){
        if(cnt == 0 || idx == n) return 0;

        if(dp[idx][buy][cnt] != -1)
            return dp[idx][buy][cnt];
        
        int profit = 0;
        if(buy){
            profit = max(-prices[idx] + solve(idx + 1 , cnt , 0 , n , prices , dp) , 
                            solve(idx + 1 , cnt , 1 , n , prices , dp));
        }
        else{
            profit = max(prices[idx] + solve(idx + 1 , cnt - 1 , 1 , n , prices , dp) ,
                            solve(idx + 1 , cnt , 0 , n , prices , dp));
        }
        return dp[idx][buy][cnt] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(3 , -1)));
        return solve(0 , 2 , 1 , n , prices , dp);
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 2 base cases
        // for cap 0 idx , buy can be anything
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>>(2 , vector<int>(3 , 0)));

        for(int idx = n - 1 ; idx >= 0 ; idx--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                for(int cnt = 1 ; cnt <= 2 ; cnt++){
                    if(buy)
                        dp[idx][buy][cnt] = max(-prices[idx] + dp[idx + 1][0][cnt] , dp[idx + 1][1][cnt]);
                    else    
                        dp[idx][buy][cnt] = max(prices[idx] + dp[idx + 1][1][cnt - 1] , dp[idx + 1][0][cnt]);
                }
            }
        }
        return dp[0][1][2];
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 2 base cases
        // for cap 0 idx , buy can be anything
        int n = prices.size();
        vector<vector<int>> after(2 , vector<int>(3 , 0));
        vector<vector<int>> curr(2 , vector<int>(3 , 0));

        for(int idx = n - 1 ; idx >= 0 ; idx--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                for(int cnt = 1 ; cnt <= 2 ; cnt++){
                    if(buy)
                        curr[buy][cnt] = max(-prices[idx] + after[0][cnt] , after[1][cnt]);
                    else    
                        curr[buy][cnt] = max(prices[idx] + after[1][cnt - 1] , after[0][cnt]);
                }
            }
        }
        return after[1][2];
    }
};