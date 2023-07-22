/*

    logic :- 
    brute force 
    [i][j] = [j][n - i - 1]

    // approch 
    // observation Jth Column is reverse and 90* to final array

    step 1 :- transpose the matrix (Row -> column)
    step 2 :- reverse the rows (diagonals stay as it-is)

    the transpose loop goes like

        | -------->
        |  | ----->
        |  | | --->    
        v  v v          (i -> n)
                            (j < i)
                                swap()
*/

#include <bits/stdc++.h>
using namespace std;

/*
    transpose and swap the cloumns
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();

        // transpose = Aij == Aji --> swapping
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j <= i ; j++)
            {
                swap(matrix[i][j] , matrix[j][i]);
            }
        }

        // reverse the matrix row wise
        for(int i = 0 ; i < row ; i++)
        {
            reverse(matrix[i].begin() , matrix[i].end());
        }
    }
};