/**
 * @file DetectCycleUnDirDFS.cpp
 * @author Striver
 * 
 * @brief > DFS method
 * 
 * @version 0.1
 * @date 2024-02-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node , int parent ,  vector<int> adj[] ,  vector<int> &vis){
        vis[node] = 1;
        for(auto child : adj[node]){
            if(!vis[child]){
                if(dfs(child , node , adj , vis) ==  true) 
                    return true;
            }
            else if(child != parent){
                return true;
            }
        }
        return false;
    }
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V , 0);
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                if(dfs(i , -1 , adj , vis)) 
                    return true;
            }
        }
        return false;
    }
};