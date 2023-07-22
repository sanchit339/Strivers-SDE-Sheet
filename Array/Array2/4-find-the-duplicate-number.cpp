/*

logic :- 
    All the brute force inlcude hasing 

    Problem of Cyclic Sort
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            if(nums[i] != i + 1){
                int correct = nums[i] - 1;
                if(nums[i] != nums[correct]){   // need to add two condotion 
                    swap(nums[i] , nums[correct]);
                }
                else{
                    return nums[i];
                }
            }
            else{
                i++;
            }
        }
        return -1;
    }
};