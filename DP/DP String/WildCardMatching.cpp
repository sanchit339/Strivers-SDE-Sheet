/**
 * @file WildCardMatching.cpp
 * @author Leetcode https://leetcode.com/problems/wildcard-matching/
 * 
 * @brief > Take Not Take for * Logic
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
    bool solve(int n , int m , string &s1 , string &s2 , vector<vector<int>> &dp){
        if(n < 0 && m < 0) return true;
        if(m < 0 && n >= 0) return false;
        if(n < 0 && m >= 0){
            for(int x = 0 ; x <= m ; x++){
                if(s2[x] != '*')
                    return false;
            }
            return true;
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        if(s1[n] == s2[m] || s2[m] == '?'){
            return dp[n][m] = solve(n - 1 , m - 1 , s1 , s2 , dp);
        }
        if(s2[m] == '*'){
            return dp[n][m] = solve(n , m - 1 , s1 , s2 , dp) || solve(n - 1 , m , s1  , s2 , dp);
        }
        return dp[n][m] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size() , m = p.size();
        vector<vector<int>>dp (n , vector<int>(m , -1));
        return solve( n - 1 , m - 1 , s , p , dp);
    }   
};  


// Convert Into 1 based indexing to avoid -ve Helpfull for tabulation

class Solution {
private:
    bool solve(int n , int m , string s1 , string s2 , vector<vector<int>> &dp){
        if(n == 0 && m == 0) return true;
        if(m == 0 && n > 0) return false;
        if(n == 0 && m > 0){
            for(int x = 1 ; x <= m ; x++){
                if(s2[x - 1] != '*')
                    return false;
            }
            return true;
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        if(s1[n - 1] == s2[m - 1] || s2[m - 1] == '?'){
            return dp[n][m] = solve(n - 1 , m - 1 , s1 , s2 , dp);
        }
        if(s2[m - 1] == '*'){
            return dp[n][m] = solve(n , m - 1 , s1 , s2 , dp) | solve(n - 1 , m , s1  , s2 , dp);
        }
        return dp[n][m] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size() , m = p.size();
        vector<vector<int>>dp (n + 1 , vector<int>(m + 1 , -1));
        return solve( n , m , s , p , dp);
    }   
};  


// Tabulation


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size() , n = p.size();
        vector<vector<bool>>dp (n + 1 , vector<bool>(m + 1 , false));

        dp[0][0] = true;

        for(int j = 1 ; j <= m ; j++){
            dp[0][j] = false;
        }

        // 3rd base case
        for(int i = 1 ; i <= n ; i++){
            bool got = true;
            for(int j = 1 ; j <= i ; j++){
                if(p[j - 1] != '*'){
                    got = false;
                    break;
                }
            }
            dp[i][0] = got;
        }

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(s[j - 1] == p[i - 1]) dp[i][j] = dp[i - 1][j - 1];

                else if(p[i - 1] == '*'){
                    dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }   
};  