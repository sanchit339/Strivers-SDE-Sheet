/*

logic :- 

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
vector <int> twoSum(vector<int>& v, int target) {
    
        vector<int>ret;
        unordered_map<int,int>m;
        // for(auto i:v) m[i]++; dont store it at start
        int n = v.size();
        for(int i=0;i<n;i++){
            int ans = target - v[i];
            if(m.find(ans)!=m.end()){
                ret.emplace_back(m[ans]); // they need indexes
                ret.emplace_back(i);
                return ret;
            }
            m[v[i]] = i;
        }
        return ret; // empty vector
    }
};