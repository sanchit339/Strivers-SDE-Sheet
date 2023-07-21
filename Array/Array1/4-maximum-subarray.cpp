
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int sum = 0 , maxi = nums[0];
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            maxi = max(sum , maxi);
            if(sum < 0) sum = 0;
        }
        return maxi;
    }
};