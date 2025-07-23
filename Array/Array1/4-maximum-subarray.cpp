
#include <bits/stdc++.h>
using namespace std;
// 1 2 3 -5 -6 7 -8 9 10 -11
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