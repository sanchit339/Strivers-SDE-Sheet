#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void findCombination(int idx , vector<int> &arr , int target , vector<vector<int>> &ans , vector<int> &temp ){
        // handling base case at last 
        if(idx == arr.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        if(arr[idx] <= target){ // pick
            temp.push_back(arr[idx]);
            // call
            findCombination(idx , arr , target - arr[idx] , ans , temp);
            //while back track remove
            temp.pop_back();
        }
        // not pick 
        findCombination(idx + 1 , arr , target , ans , temp); // target as it is as we havent pick the idx
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Create a helper function 
        vector<vector<int>>ans;
        vector<int>temp;
        findCombination(0 , candidates , target , ans , temp);
        return ans;
    }
};