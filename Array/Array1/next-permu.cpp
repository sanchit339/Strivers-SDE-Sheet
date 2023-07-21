/*
    whats the question 
    123 => 132 => 312 => 123  ----> next greater / next element as per sequesce
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size() , k , l;
        for(k = n-2 ; k >= 0 ; k--){ // find break point
            if(nums[k] < nums[k+1]){ 
                break; // k is defined globally  we get the k value here
            } 
        }
        if(k < 0){
            reverse(nums.begin(),nums.end()); // no break point
        } else{
            for(l = n-1 ; l > k ; l--){ // if no break point do 2nd itr from notes
                if(nums[l] > nums[k]){
                    break; // if got 
                }
            }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1 , nums.end()); // reverse from that + 1 index
        }
    }
};

