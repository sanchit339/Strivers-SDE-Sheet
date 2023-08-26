/**
 * @file SubSeqSumK.cpp
 * @author GFG practice
 * 
 * @brief > Depends on Boolean Logic
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
    bool solve(int n , int target , vector<int> &nums , vector<vector<int>> &dp){
        if(target == 0) return true;
        if(n == 0) return target == nums[0];

        if(dp[n][target] != -1 )
            return dp[n][target];

        bool notTake = solve(n - 1 , target , nums , dp);
        bool take = false;
        if(nums[n] <= target) take = solve(n - 1 , target - nums[n] , nums , dp);

        return dp[n][target] = take | notTake;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n , vector<int> (sum + 1 , -1));
        return solve(n , sum , arr , dp);
    }
};

class Solution{
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<bool>> dp(n , vector<bool> (sum + 1 , false));
        
        // for all idx make target 0
        for(int i = 0 ; i < n ; i++) dp[i][0] = true;

        // extra base case 
        dp[0][arr[0]] = true;

        for(int ind = 1 ; ind < n ; ind++){
            for(int target = 1 ; target <= sum ; target++){
                bool notTake = dp[ind - 1][target];
                bool take = false;
                if(arr[ind] <= target)
                    take = dp[ind - 1][target - arr[ind]]; // here sub

                dp[ind][target] = take | notTake;
            }
        }
        return dp[n - 1][sum];
    }
};