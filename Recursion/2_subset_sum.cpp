
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void subSet(int idx , vector<int>& arr  , vector<vector<int>> &ans , vector<int>temp){
        
        ans.push_back(temp);

        for(int i = idx ; i < arr.size() ; ++i){
            // distinct 
            if(i > idx && arr[i] == arr[i-1]) continue;
            temp.push_back(arr[i]);
            subSet(i + 1 , arr ,  ans , temp);
            temp.pop_back(); // as we used loop we not taking the not took condition (IG)
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        // sort and disinct
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin() , nums.end());
        subSet(0 , nums ,  ans , temp);
        return ans;
    }
};