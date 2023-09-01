/**
 * @file DistinctSubSeq.cpp
 * @author Leetcode https://leetcode.com/problems/distinct-subsequences/
 * 
 * @brief >> Count Subseq
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
    int solve(int i , int j , string s , string t , vector<vector<int>>& dp){
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == t[j])
            return dp[i][j] = solve(i - 1 , j - 1 , s , t , dp) + solve( i - 1 , j , s , t , dp);

        else return dp[i][j] = solve(i - 1 , j , s , t , dp);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size() , m = t.size();
        vector<vector<int>> dp( n , vector<int>(m , -1));
        return solve(n - 1 , m - 1 , s , t , dp);
    }
};


class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size() , m = t.size();
        vector<vector<double>> dp( n + 1 , vector<double>(m + 1 , 0));
        
        // base case for every j == 0 make it 1
        for(int i = 0 ; i <= n ; i++){
            dp[i][0] = 1;
        } // i has be set 0 default
        for(int j = 1 ; j <= m ; j++)
            dp[0][j] = 0;

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                
                else 
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return (int)dp[n][m];
    }
};

// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int n = s.size() , m = t.size();
//         vector<double> curr(n , 0) , prev(m , 0);
        
//         prev[0] = curr[0] = 1;

//         for(int i = 1 ; i <= n ; i++){
//             for(int j = 1 ; j <= m ; j++){
//                 if(s[i - 1] == t[j - 1])
//                     dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                
//                 else 
//                     dp[i][j] = dp[i - 1][j];
//             }
//         }
//         return (int)dp[n][m];
//     }
// };