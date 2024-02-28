/**
 * @file NumberOFProv.cpp
 * 
 * @brief > Same as number of Connected components
 * 
 * @date 2023-08-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
   void dfs(int node , vector<int> adjLS[] , vector<int> &vis){
        vis[node] = true;
        for(auto child : adjLS[node]){
            if(vis[child]) continue;
            dfs(child , adjLS , vis);
        }
   }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        // will create Adj List
        vector<int> adjLS[V];
        for(int i = 0 ; i < V ; ++i){
            for(int j = 0 ; j < V ; ++j){
                if(adj[i][j] == 1 && i != j){
                    adjLS[i].push_back(j);
                    adjLS[j].push_back(i);
                }
            }
        }

        vector<int>vis(V , 0);
        int cnt = 0;
        for(int i = 0 ; i <= V ; i++){
            if(!vis[i]){
                dfs(i , adjLS , vis);
                cnt++;
            }
        }
        return cnt;
    }
};