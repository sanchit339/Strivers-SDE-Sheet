/**
 * @file UniquePattern.cpp
 * @author Striver
 * 
 * @brief > count the unique path source to destination
 *        > 0 , 0 = 1 
 *  
 *         |   
 *         |  2 possible paths
 *    <----|
 *  
 * @version 0.1
 * @date 2023-08-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int m, int n , vector<vector<int>> dp){
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;

        if(dp[m][n] != -1)
            return dp[m][n];

        int up = solve(m - 1 , n , dp);
        int left = solve(m , n - 1 , dp);

        return  dp[m][n] = up + left;
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return solve(m - 1 , n - 1 , dp);
    }
};

/*
    1 1 1 1 1 1 1 
    1 2 3 4 5 6 7 
    1 3 6 10 15 21 28 
*/
class SolutionOpti{ // dosent work 
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(m , 0);

        for(int i = 0 ; i < m ; i++){
            vector<int>curr(n , 0);
            for(int j = 0 ; j < n ; j++){
                if(i == 0 && j == 0) curr[j] = 1;
                else{
                    int up = 0;
                    int left = 0;
                    if(i > 0)
                        up = prev[j];

                    if(j > 0)
                        left = curr[j - 1];

                    curr[j] = up + left;
                }
            }
            prev = curr; // swap
        }
        return prev[n - 1];
    }
};

class Solution{
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n , -1));

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int up = 0;
                    int left = 0;
                    if(i > 0)
                        up = dp[i - 1][j];

                    if(j > 0)
                        left = dp[i][j - 1];

                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};