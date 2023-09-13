/**
 * @file LongestIncSubseq.cpp
 * @author Striver
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
    int solve(int idx , int prev_idx , int n , vector<int> &nums , vector<vector<int>> &dp){
        if(idx == n) return 0;
        if(dp[idx][prev_idx + 1] != -1)
            return dp[idx][prev_idx + 1];
        
        int len = solve(idx + 1 , prev_idx , n , nums , dp);
        if(prev_idx == -1 || nums[idx] > nums[prev_idx])
            len = max(len , 1 + solve(idx + 1 , idx , n , nums , dp)); // prev_idx === idx now
        
        return dp[idx][prev_idx + 1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(n + 1 , -1));
        return solve(0 , -1 , n , nums , dp);
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , 0));

        // for any idx and n const -> put 0
        for(int idx = n - 1 ; idx >= 0 ; --idx){
            for(int prev_idx = idx - 1 ; prev_idx >= -1 ; --prev_idx){
                int len = dp[idx + 1][prev_idx + 1];
                if(prev_idx == -1 || nums[idx] > nums[prev_idx]){
                    len = max(len , 1 + dp[idx + 1][idx + 1]);
                }
                dp[idx][prev_idx + 1] = len;
            }
        }
        return dp[0][0];
    }
};