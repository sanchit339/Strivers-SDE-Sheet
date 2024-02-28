/**
 * @file DetectCycleUnDirBFS.cpp
 * @author Striver
 * 
 * @brief > TC = O(N) + 2E
 *        > SC = O(N) + O(N) + O(N)
 *              store   vis    queue
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
    bool detectCycle(int src, vector<int>  adj[] , vector<int> vis){
        vis[src] = 1;
        queue<pair<int,int>>q;
        q.push({src , -1});
        
        while (!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;

            q.pop();
            for(auto child : adj[node]){
                if(!vis[child]){
                    vis[child] = 1;
                    q.push({child , node});
                }
                else if(child != parent){ // 2 -> 5 child of 5 are 6 then 2 is vis already also 2 is parent
                    return true;
                }
            }
        }
        return false;
    }
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V , 0);

        // for components
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                if(detectCycle(i, adj , vis)) return true;
            }
        }
        return false;
    }
};