/*

logic :- 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& price) {

        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int mini = price[0] , n = price.size(); //price at 1st day 
        int maxProfit = 0; // as per day 1 profit 
        for(int i=0;i<n;i++){
            int profit = price[i] - mini; // profit ON ith day
            maxProfit = max(maxProfit , profit);
            mini = min(mini , price[i]);
        }
        return maxProfit;
    }
};