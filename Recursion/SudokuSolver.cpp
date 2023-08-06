#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board); // update 
    }

    bool solve(vector<vector<char>>& board){
        for(int i = 0 ; i < board.size() ; ++i){
            for(int j = 0 ; j < board[0].size() ; ++j){
                if(board[i][j] == '.'){
                    for(int c = '1' ; c <= '9' ; ++c){
                        if(isValidate(board , i , j , c)){
                            board[i][j] = c;

                            if(solve(board) == true){
                                return true;
                            }
                            // backtreack 
                            board[i][j] = '.';
                        }
                    }
                    return false; // for each recursion
                }
            }
        }
        return true;
    }

    bool isValidate(vector<vector<char>>& board , int row , int col , int c){
        // check row , column
        for(int i = 0 ; i < 9 ; ++i){
            if(board[row][i] == c) return false;

            if(board[i][col] == c) return false;

            if(board[3 * (row / 3) + i / 3] [3 * (col / 3) + i % 3] == c){
                return false;
            }
        }
        return true;
    }
};