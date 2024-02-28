/**
 * @file DFS.cpp
 * 
 * @brief SC = O(N) +  O(N)  +  O(N)
 *           Storing  Visited  Recursion Stack Space
 *        
 *        TC (For Undirected 2E) O(N) + 2E = O(N)
 *        TC (For Directed E(Depends)) 
 * @version 0.1
 * @date 2023-08-11
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void DFS(int node , vector<int> adj[] , vector<int> &ans , vector<int> &vis){
        vis[node] = true;
        ans.push_back(node);
        for(auto child : adj[node]){
            if(vis[child]) continue;
            DFS(child , adj , ans , vis);
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> vis(V , 0);
        
        DFS(0 , adj , ans , vis);
        
        return ans;
    }
};