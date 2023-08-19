/**
 * @file fibboBottomUp.cpp
 * @author Striver
 * 
 * @brief > Bottom up approch 
 *        > SC = O(1) TC(N)  
 * 
 * @version 0.1
 * @date 2023-08-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int prev = 1, prev2 = 0;
    for(int i = 2; i <= n ; i++){
        int curri = prev2 + prev;
        prev2 = prev;
        prev = curri;
    } 
    cout << prev;
}