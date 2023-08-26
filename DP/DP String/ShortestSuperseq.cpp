/**
 * @file ShortestSuperseq.cpp
 * @author Leetcode
 * @brief 
 * @version 0.1
 * @date 2023-08-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                
                else dp[i][j] = max(dp[i][j - 1] , dp[i - 1][j]);
            }
        }

        string ans = "";
        int i = n , j = m;
        while( i > 0 && j > 0 ){
            if(s1[i - 1] == s2[j - 1]){
                ans += s1[i - 1];
                --i , --j;
            }
            else if(dp[i - 1][j] > dp[i][j - 1]){
                ans += s1[i - 1] ; // took from left
                --i;
            }
            else{
                ans += s2[j - 1];
                --j;
            }
        }
        // if still remain
        while(i > 0){
            ans += s1[i - 1];
            --i;
        } 
        while(j > 0){
            ans += s2[j - 1];
            --j;
        } 

        // as we itr from bottom 
        reverse(ans.begin() , ans.end());
        return ans;
    }
};