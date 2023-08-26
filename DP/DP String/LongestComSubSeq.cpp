/**
 * @file LongestComSubSeq.cpp
 * @author Striver Leetcode
 * 
 * @brief >> Equal both - / i -j / -i j
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
    int solve(int n , int m , string s1 , string s2 , vector<vector<int>>& dp){
        if(n < 0 || m < 0)
            return 0;
        
        if(dp[n][m] != -1)
            return dp[n][m];

        if(s1[n] == s2[m]) return dp[n][m] = 1 + solve(n - 1 , m - 1 , s1 , s2 , dp);

        return dp[n][m] = max(solve(n - 1 , m , s1 , s2 , dp) , solve(n , m - 1 , s1 , s2 , dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() , m = text2.size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        return solve(n - 1 , m - 1 , text1 , text2 , dp);
    }
};


class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                
                else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};

