/**
 * @file ForgKjumps.cpp
 * @author Atcoder
 * 
 * @brief Min of K 
 * 
 * @version 0.1
 * @date 2023-08-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    int solve(int n , int k , vector<int> &nums , vector<int> &dp){
        if(n == 0)
            return 0;

        if(dp[n] != -1)
            return dp[n];
        
        int minStep = INT_MAX;
        for(int i = 1 ; i <= k ; i++){
            int jump = 0;
            if(n - i >= 0){
                jump = solve(n - i , k , nums , dp) + abs(nums[n] - nums[n - i]);
                minStep = min(jump , minStep);
            }
        }
        return dp[n] = minStep;
    }
public:
    int KJumps(int n , int k , vector<int> &nums){
        vector<int>dp(n , -1);

        return solve(n - 1 , k , nums , dp);
    }
};


class Solution1{
public:
    int KJump(int n , int k , vector<int> &nums){
        vector<int> dp(n , -1);
        dp[0] = 0;

        for(int i = 0 ; i <= n ; i++){
            int minStep = INT_MAX;
            for(int j = 1 ; j <= k ; j++){
                if(i - j >= 0){
                    int jump = dp[ i - j ] + abs(nums[n] - nums[n - j]);
                    minStep = min(minStep , jump);
                }
                dp[i] = minStep;
            }
        }
        return dp[n - 1];
    }
};

int main(){
    int n , k;
    cin >> n >> k;

    vector<int> v(n);
    for(auto &it : v) cin >> it;

    Solution1 ans;
    cout << ans.KJump(n , k , v);
}