#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    void subSum(int idx , vector<int> arr , int n , int sum , vector<int> &ans){
        // base case 
        if(idx == n){
            ans.push_back(sum);
            return;
        }
        
        // take
        subSum(idx + 1 , arr , n , sum +  arr[idx] , ans);

        //not take
        subSum(idx + 1 , arr , n , sum , ans);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        subSum(0 , arr , N , 0 , ans);
        sort(ans.begin() , ans.end());
        return ans;
    }
};