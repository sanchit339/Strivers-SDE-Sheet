/**
 * @file PalindromicPartitions.cpp
 * @author Striver
 * @brief Longest Palindrome
 * @version 0.1
 * @date 2023-09-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(string a, string b){
        int n = a.size() , m = b.size();
        vector<vector<int>>dp(n + 1 , vector<int>(m + 1 , 0));
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(a[i - 1] == b[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }   
        }
        return dp[n][m];
    }
public:
    int longestPalindromeSubseq(string s) {
        string b = s;
        reverse(s.begin() , s.end());
        return solve(b , s);
    }
};

