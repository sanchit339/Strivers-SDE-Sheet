/**
 * @file BFS.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> vis(V , 0);
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            vis[top] = true;
            ans.push_back(top);
            for(auto it : adj[top]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = true;
                }
            }
        }
        return ans;
    }
};