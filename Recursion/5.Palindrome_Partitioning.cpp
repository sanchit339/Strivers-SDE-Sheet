#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(int idx , vector<int> &nums , vector<vector<int>> &ans){
        int n = nums.size();
        if(idx == n){
            ans.push_back(nums);
            return;
        }

        for(int i  = idx ; i < n ; i++){
            swap(nums[i] , nums[idx]);
            solve(idx + 1 , nums , ans);
            swap(nums[i] , nums[idx]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0 , nums , ans);
        return ans;
    }
};