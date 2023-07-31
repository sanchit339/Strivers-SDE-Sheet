
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief kept a freq array
 * 
 *  for N array N! permutation can be 
 */

class Solution {
private:
    void recursive( vector<int>& arr , vector<vector<int>> &ans , vector<int>& temp , vector<int> &freq){
        // base case 
        if(temp.size() == arr.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = 0 ; i < arr.size() ; i++){  // iterate from zero
            if(!freq[i]){
                freq[i] = 1;
                temp.push_back(arr[i]);
                recursive(arr , ans , temp , freq);
                freq[i] = 0;
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        vector<int> freq (nums.size() , 0);

        recursive( nums , ans , temp , freq);
        return ans;
    }
};
/**
 * @brief TC = N! * N (for loop)
 */
class Solution {
private:
    void Permutation(int idx , vector<int>& arr , vector<vector<int>>& ans){
        // base case
        if(idx == arr.size()){
            ans.push_back(arr); // as we are swapping we dont need temp (DS)
            return;
        }

        for(int i = 0 ; i < arr.size() ; i++){
            swap(arr[i] , arr[idx]);
            Permutation(0 , arr , ans);
            swap(arr[i] , arr[idx]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        Permutation(0 , nums , ans);
        return ans;
    }
};