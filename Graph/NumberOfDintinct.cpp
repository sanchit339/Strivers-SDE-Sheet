
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& vis , vector<pair<int,int>> &v , int br , int bc){
        int n = grid.size() , m = grid[0].size();
        if(i < 0 || j < 0) return;
        if(i >= n || j >= m) return;
        if(vis[i][j] || grid[i][j] == 0) return;

        v.push_back({i - br, j - bc});
        vis[i][j] = 1;

        dfs(i + 1 , j , grid , vis , v , br , bc);
        dfs(i - 1 , j , grid , vis , v , br , bc);
        dfs(i , j + 1 , grid , vis , v , br , bc);
        dfs(i , j - 1 , grid , vis , v , br , bc);
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid){
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m , 0));
        set<vector<pair<int,int>> > s;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    vector<pair<int,int>> v;
                    dfs(i , j , grid , vis , v , i , j);
                    s.insert(v);
                }
            }
        }
        int ans = s.size();
        return ans;
    }
};

