#include<bits/stdc++.h>
using namespace std;

/*  N SC extra for hashing */
class Solution {
public:
    void placeQueen(int col , int n , vector<vector<string>> &ans , vector<string> &temp , vector<int> &leftRow , vector<int> &upperDia , vector<int> &lowerDia){
        if(col == n){
            ans.push_back(temp);
            return;
        }

        for(int row = 0 ; row < n ; row++){
            if(leftRow[row] == 0 && lowerDia[row + col] == 0 && upperDia[n - 1 + col - row] == 0){ // see the function call
                
                temp[row][col] = 'Q';
                
                leftRow[row] = 1;
                lowerDia[row + col] = 1;
                upperDia[n - 1 + col - row] = 1;
                
                placeQueen(col + 1 , n , ans , temp , leftRow , upperDia , lowerDia);
                
                temp[row][col] = '.';

                leftRow[row] = 0;
                lowerDia[row + col] = 0;
                upperDia[n - 1 + col - row] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> ans;
            vector<string> temp(n);
            string s(n , '.');
            for(int i = 0 ; i < n ; i++){
                temp[i] = s;
            }
            // maintain hashing
            vector<int> leftRow( n , 0) , upperDia(2 * n - 1, 0) , lowerDia(2 * n - 1 , 0); // -1 coz that is occupied
            placeQueen(0 , n , ans , temp , leftRow , upperDia , lowerDia);
            return ans;
    }
};