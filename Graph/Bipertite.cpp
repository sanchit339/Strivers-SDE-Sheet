/**
 * @file Bipertite.cpp
 * @author your name (you@domain.com)
 * 
 * @brief > The Adjacent colours are unidentical (with Only 2 Colours)
 *        > Liner graphs with no cycles are always bipertite
 *        > With Even Cycle Length are Bipertite
 * 
 * @version 0.1
 * @date 2024-02-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	bool bfs(int start , vector<int>graph[] , vector<int> &color){
        queue<int>q;
        q.push(start);

        color[0] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                // if Not colored
                if(color[it] == -1){
                    color[it] = !color[node]; // color oppo to node
                    q.push(it);
                }
                // if cannot color (parent == child)
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(int V, vector<int>adj[]){
        vector<int> color (V , -1);
	    for(int i = 0; i < V; i++){ // cycles can be there so
	        if(color[i] == -1){
	            if(bfs(i, adj, color) == false) return false;
	        }
	    }
        return true;
	}
};