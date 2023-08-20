/**
 * @file FrogJump.cpp
 * @author https://www.codingninjas.com/studio/problems/frog-jump_3621012
 * 
 * @brief OverLaping Problem 
 * 
 * @version 0.1
 * @date 2023-08-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h> 
using namespace std;

int solve(int n , vector<int> &heights , vector<int> &dp){
    if(n == 0){
        return 0;
    }
    if(dp[n] != -1)
        return dp[n];
    
    int left = solve(n - 1, heights , dp) + abs(heights[n] - heights[n - 1]);
    int right = INT_MAX;
    if(n > 1)
        right = solve(n - 2, heights , dp) + abs(heights[n] - heights[n - 2]);

    return dp[n] = min(left , right);
}

int frogJump(int n, vector<int> &heights){
    vector<int> dp(n + 1 , -1);
    return solve(n - 1, heights , dp);
}

// Bottom Up Approch (Tabulation)

int frogJumpTab(int n , vector<int> &heights){
    vector<int> dp(n + 1 , -1);
    dp[0] = 0;

    for(int i = 1 ; i < n ; i++){
        int left = dp[i - 1] + abs(heights[n] - heights[n - 1]);
        int right = INT_MAX;
        if(i > 1)
            right = dp[i - 2] + abs(heights[n] - heights[n - 2]);
        
        dp[i] = min(left , right);
    }
    return dp[n - 2];
}

// Space Optimization


int frogJumpSO(int n , vector<int> &heights){
    int previ = 0 , prev2 = 0;

    for(int i = 1 ; i < n ; i++){
        int left = previ + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if(i > 1)
            right = prev2 + abs(heights[i] - heights[i - 2]);
        
        int curri = min(left , right);
        
        prev2 = previ;
        previ = curri;

    }
    return previ;
}


// for K JUmps

#include <bits/stdc++.h>
using namespace std;

int helper(int n, int k, vector<int> &heights) {
	if(n == 0) return 0;

	int minSteps = INT_MAX;

	for(int j=1; j<=k; j++) {
		int l = INT_MAX;
		if(n-j >= 0)
			l = helper(n-j, k, heights) + abs(heights[n] - heights[n-j]);
		minSteps = min(minSteps, l);
	}

	return minSteps;
}

int frogKJump(int n, int k, vector<int> &heights) {
	return helper(n-1, k, heights);
}

int main(){
	vector<int> heights;
	heights = {10, 20, 30, 10};
	cout << frogKJump(4, 2, heights);
	cout << endl;
	heights = {10, 50, 10};
	cout << frogKJump(3, 2, heights);
}