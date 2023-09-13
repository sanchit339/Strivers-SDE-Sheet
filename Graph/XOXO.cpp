/**
 * @file XOXO.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
	void solve(int i , int j , int n , int m , vector<vector<char>> &mat , vector<vector<char>> &ans , vector<vector<int>> &vis){
		if( i < 0 || j < 0) return;
		if(i >= n || j >= m) return;
		if(mat[i][j] == 'X' || vis[i][j]) return;
		
		ans[i][j] = 'O';
		vis[i][j] = 1;

		solve( i - 1 , j , n , m , mat , ans , vis);
		solve( i + 1 , j , n , m , mat , ans , vis);
		solve( i , j - 1 , n , m , mat , ans , vis);
		solve( i , j + 1 , n , m , mat , ans , vis);
	}
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
		vector<vector<char>> ans(n , vector<char>(m , 'X'));
		vector<vector<int>> vis(n , vector<int>(m , 0));
		for(int i = 0 ; i < n ; i++){
			if(!vis[i][0] && mat[i][0] == 'O')
				solve(i , 0 , n , m , mat , ans , vis);
		}
		for(int i = 0 ; i < n ; i++){
			if(!vis[i][m - 1] && mat[i][m - 1] == 'O')
				solve(i , m - 1 , n , m , mat , ans , vis);
		}
		for(int j = 0 ; j < m ; j++){
			if(!vis[0][j] && mat[0][j] == 'O')
				solve(0 , j , n , m , mat , ans , vis);
		}
		for(int j = 0 ; j < m ; j++){
			if(!vis[n - 1][j] && mat[n - 1][j] == 'O')
				solve(n - 1 , j , n , m , mat , ans , vis);
		}
		return ans;
    }
};