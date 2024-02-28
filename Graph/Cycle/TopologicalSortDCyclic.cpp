/**
 * @file TopologicalSortDCyclic.cpp
 * @author your name (you@domain.com)
 * 
 * @brief > Topogical Sort for Direted Graph With Cycles
 *        > Check the image at the start the one is removed
 *        > but the indegree of 2 is reduced to 1 still not zero 
 *        > the queue is empty, also 2 cannot be placed in the queue
 *        > so, the traditional topological function fails here
 *          
 *        > if You are able to genereate a topological sort then cycle does not exist 
 *        > if you aren't  able to generate then cycle is present
 * 
 * @version 0.1
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> inDeg(V , 0);
        for(int i = 0 ; i < V ; i++){
            for(auto it : adj[i]){
                inDeg[it]++;
            }
        }
        
        queue<int>q;
        for(int i = 0 ; i < V ; ++i){
            if(inDeg[i] == 0)
                q.push(i);
        }
        
        // here if we fail to generate a topological sort then cycle exist
        // rather than generating vector we maintain a count 
        // to save the space
        int cnt = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            cnt++;
            for(auto child : adj[node]){
                inDeg[child]--;
                if(inDeg[child] == 0)
                    q.push(child);
            }
        }
        
        if(cnt == V) return false; // No Cycle
        return true; // cycle found
    }
};



