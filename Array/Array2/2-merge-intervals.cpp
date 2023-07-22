/*

logic :- 
    [1 , 3] [2 , 6] = {overlap [3] [2]} ->> [1 , 6]
    merge it [1,3] [2,6] --- [2 < 3] so new vec = max(3 , 6) to update in new vector
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged_intervals;

        // base case
        if(intervals.size() == 0) return merged_intervals;

        //sort the intervals if not mentioned they are sorted
        sort(intervals.begin() , intervals.end());

        //temp storage
        vector<int>temp = intervals[0]; // convenient to use

        for(auto it : intervals)
        {
            // two condition  1. Asssign , 2.Push in answer
            if(it[0] <= temp[1]) // check if swapable
            {
                temp[1] = max(it[1], temp[1]);  // as 0th will remane same
            }
            else // [2 , 6] [8 , 10] ---> cannot be merged
            { 
                merged_intervals.emplace_back(it); 
                // update the temp 
                temp = it;
            }
        }
        // push the remaining merged interval last one
        merged_intervals.emplace_back(temp);

        return merged_intervals;
    }
};