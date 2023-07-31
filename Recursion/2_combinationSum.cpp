#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void findCombibnation(int idx , vector<int>& arr , int target , vector<vector<int>> &ans , vector<int> &temp){

        // base case as it might not go end
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        // as we checking all the possible recuresion
        for(int i = idx ; i < arr.size() ; i++){

            // unique check 
            if(i > idx && arr[i] == arr[i - 1]) continue; // avoid segmen.. in ( == ) and [1 ,1 , 1] i > idx at some time idx const.. till loop

            // total check
            if(arr[i] > target) break; // cannot subtract
            //pick 
            temp.push_back(arr[i]);
            findCombibnation(i + 1 , arr , target - arr[i] , ans , temp); // + 1 distinct one so..

            // not pick
            temp.pop_back(); // backtrack
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target ){
        // unique and sorted is required 
        
        /*
            ---------->
              -------->
                ------>
                  ---->
                    -->
                      >
        */

        // .. sort 
        sort(candidates.begin() , candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        findCombibnation(0 , candidates , target , ans , temp);
        return ans;
    }
};