/**
 * @file TrainingNinja.cpp
 * @author Coding Ninja
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

int main(){
    int n; cin >> n;
    vector<vector<int>> points(n , vector<int>(3));

    for(auto &vec : points){
        for(auto &it : vec){
            cin >> it;
        }
    }

    cout << ninjaTraining(n , points);
}