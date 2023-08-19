/**
 * @file ClimbingStair.cpp
 * @author https://leetcode.com/problems/climbing-stairs/
 * 
 * @brief 
 * 
 * @version 0.1
 * @date 2023-08-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int climb(int n , vector<int> &dp){
        if(n <= 2)
            return n;
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = climb(n - 1 , dp) + climb(n - 2 , dp);
    }
public:
    int climbStairs(int n) {
        int count = 0;
        vector<int>dp(n + 1  , -1);
        return climb(n , dp);
    }
};