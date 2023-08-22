/**
 * @file TrainingNinja.cpp
 * @author Atcoder DP Contest
 * 
 * @brief 
 * 
 * @version 0.1
 * @date 2023-08-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// TC N * 4 * 3 // SC = N*4 + O(N) stack spcae
int solve(int day , int last , vector<vector<int>> &points , vector<vector<int>> &dp){
    // base case
    if(day == 0){
        int maxi = -1;
        for(int task = 0 ; task < 3 ; task++){
            if(task != last)
                maxi = max(maxi , points[0][task]);
        }
        return maxi;
    }

    if(dp[day][last] != -1)
        return dp[day][last];

    int maxi = -1;
    for(int task = 0 ; task < 3 ; task++){
        if(task != last){
            int point = points[day][task] + solve(day - 1 , task , points , dp);
            maxi = max(maxi , point);
        }
    }

    return dp[day][last] = maxi;    
}

int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n , vector<int>(4 , -1));

    return solve(n - 1 , 3 , points , dp);
}

class Solution{ // TC N * 4 * 3 // SC = N*4
public:
    int HomeWork(int n , vector<vector<int>> &points){
        vector<vector<int>> dp(n , vector<int>(4 , 0)); // (3 for days) extra if its last day 
        
        // base case will have 4 values
        dp[0][0] = max(points[0][1] , points[0][2]);
        dp[0][1] = max(points[0][0] , points[0][2]);
        dp[0][2] = max(points[0][0] , points[0][1]);
        dp[0][3] = max(points[0][0] , max(points[0][1] , points[0][2]));

        for(int day = 1 ; day < n ; day++){
            for(int last = 0 ; last < 4 ; last++){
                // dp[day][last] = 0;
                for(int task = 0 ; task < 3 ; task++){
                    if(task != last){
                        int point = points[day][task] + dp[day-1][task];
                        dp[day][last] = max(dp[day][last] , point); // last means from the curr exc last one
                    }
                }
            }
        }
        return dp[n - 1][3]; // compute and use the last one
    }
};


class SpaceOpti{ // TC Only
public:
    int HomeWork(int n , vector<vector<int>> &points){
        
        vector<int> prev(4 , 0); // (3 for days) extra if its last day 
        // base case will have 4 values
        prev[0] = max(points[0][1] , points[0][2]);
        prev[1] = max(points[0][0] , points[0][2]);
        prev[2] = max(points[0][0] , points[0][1]);
        prev[3] = max(points[0][0] , max(points[0][1] , points[0][2]));

        for(int day = 1 ; day < n ; day++){
            vector<int> temp(4 , 0);
            for(int last = 0 ; last < 4 ; last++){
                // dp[day][last] = 0;
                for(int task = 0 ; task < 3 ; task++){
                    if(task != last){
                        int point = points[day][task] + prev[task];
                        temp[last] = max(temp[last] , point); // last means from the curr exc last one
                    }
                }
            }
        }
        return prev[3]; // compute and use the last one
    }
};

int main(){
    int n; cin >> n;
    vector<vector<int>> points(n , vector<int>(3));

    for(auto &vec : points){
        for(auto &it : vec){
            cin >> it;
        }
    }

    // Solution ans;
    // cout << ans.HomeWork(n , points);

    SpaceOpti optiAns;
    cout << optiAns.HomeWork(n , points);

    // cout << ninjaTraining(n , points);
}