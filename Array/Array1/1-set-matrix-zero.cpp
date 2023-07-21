/*
1st interation takes and stores the 0 

stored in unordered 

2nd iteration make the [ i ] [ j ] th zero if R / C has the 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        unordered_set<int> row , column;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; ++j){
                if(matrix[i][j] == 0){
                    row.insert(i) , column.insert(j);
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(row.count(i) > 0 || column.count(j) > 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};