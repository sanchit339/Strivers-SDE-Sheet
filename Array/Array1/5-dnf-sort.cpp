/*

logic :- 

    low = 0 , mid = 0 
    DNF low = 1 , mid = ? , high = 2
    if zero swap low  , mid | low++ mid ++
    if 1 
    if two swap mid and high | high--
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0 , mid = 0 , high = nums.size() - 1;
        while(mid <= high){
            if(nums[mid] == 0){
                swapp(nums,low,mid);
                low++ , mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swapp(nums,mid,high);
                high--;
            }
        }
    }
    void swapp(vector<int>& arr , int i , int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    } 
};
