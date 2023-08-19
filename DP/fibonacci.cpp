/**
 * @file fibonacci.cpp
 * @author Striver
 * 
 * @brief > Momoization 
 *        > TC = O(N) , SC = O(N)..stack + O(N)..vector  
 * @version 0.1
 * @date 2023-08-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int fibo(int n , vector<int> &dp){
    if(n <= 1)
        return n;
    if(dp[n] != -1)
        return dp[n];
    
    return dp[n] = fibo(n - 1 , dp) + fibo(n - 2  , dp);
}

int main(){
    int n ; cin >> n;
    vector<int> dp(n + 1 , -1);

    int ans = fibo(n , dp);

    cout << ans << endl;
}