/**
 * @file EditDistance.cpp
 * @author Leetcode https://leetcode.com/problems/edit-distance/
 * 
 * @brief  Min of All (Insert , Delete , Replace)
 * 
 * @version 0.1
 * @date 2023-08-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int n , int m , string s1 , string s2 , vector<vector<int>> dp){
        if( n < 0 ) return m + 1;
        if( m < 0 ) return n + 1;

        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(s1[n] == s2[m]) return solve(n - 1 , m - 1 , s1 , s2 , dp);
        else 
            return 1 + min(solve(n , m - 1, s1 , s2 , dp) , min(solve(n - 1 , m , s1 , s2 , dp) , solve(n - 1 , m - 1 , s1 , s2 , dp)));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size() , m = word2.size();
        vector<vector<int>> dp( n , vector<int>(m , -1));
        return solve(n - 1 , m - 1 , word1 , word2 , dp);
    }
};


class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size() , m = word2.size();
        vector<vector<int>> dp( n + 1 , vector<int>(m + 1, 0));
        
        for(int i = 0 ; i <= n ; i++) dp[i][0] = i;
        for(int j = 0 ; j <= m ; j++) dp[0][j] = j;

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                
                else{
                    dp[i][j] = 1 + min(dp[i - 1][j] , min(dp[i][j - 1] , dp[i - 1][j - 1]));
                }
            }
        }
        return dp[n][m];
    }
};