/**
 * @file HouseRober_1.cpp
 * @author LeetCode https://leetcode.com/problems/house-robber/description/
 * 
 * @brief > Pick AND Not Pick Logic As we are going through Adj 
 *        > O(N) TC
 *        > O(N) SC stack O(N) DP space
 *   
 * @version 0.1
 * @date 2023-08-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int n , vector<int> &nums , vector<int> &dp){
        if(n == 0)
            return nums[0];
        if(n < 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        int notPick = solve(n - 1 , nums , dp);
        int pick = nums[n] + solve(n - 2 , nums , dp);
        
        return dp[n] = max(pick , notPick);
    }

private:
    int TabRob(vector<int> & nums){
        int n = nums.size();
        vector<int> dp(n , -1);

        dp[0] = 0;
        for(int i = 1 ; i < n ; i++){
            int notPick = dp[i - 1];
            int pick = nums[i];
            if(i > 1)
                pick += dp[n - 2];
            
            dp[i] = max(pick , notPick);
        }
        return dp[n - 1];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        vector<int> dp(n + 1 , -1);
        return solve(n - 1, nums , dp);        
    }
};
