/*

logic :- 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // no extra space required
        int a = m - 1 , b = n - 1 , last = m + n - 1;

        while (a >= 0 and b >= 0) // "and" coz remaining will be handled at the last
        {
            if(nums1[a] > nums2[b])
            {
                // put at last
                nums1[last] = nums1[a];
                --a;
            }
            else
            {
                nums1[last] = nums2[b];
                --b;
            }
            last--;
        }
        while(b >= 0)
        {
            nums1[last] = nums2[b];
            --b;
            --last;
        }
    }
};