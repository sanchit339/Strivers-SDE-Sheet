#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    int solve(int n , vector<int> &jump , vector<int> &dp){
        if(n == 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];

        int first = solve(n - 1 , jump , dp) + abs(jump[n] - jump[n - 1]);
        int second = INT_MAX;
        if(n > 1)
            second = abs(jump[n] - jump[n - 2]) + solve(n - 2 , jump , dp);
        
        return dp[n] = min(first , second);
    }
public:
    int frogJump(int n , vector<int> &jump){
        vector<int> dp(n , -1);
        dp[0] = 0;
        return solve(n - 1 , jump , dp);
    }
};


int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto &it : v) cin >> it;

    Solution ans;
    cout << ans.frogJump(n , v);
}