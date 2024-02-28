/**
 * @file TopologicalBFSDFS.cpp
 * @author Striver
 * 
 * @brief > Only Works on DAG 
 *        > There multiple valid orders any one returning is okay  
 *          
 *        > Linear Ordering of vertices such that is there an edge between u & v , 
 *          u apperas before v in the ordering
 * 
 *  Eg :- 6 edges
 *  5 0
 *  4 0
 *  5 2 
 *  4 1
 *  2 3
 *  2 1 
 *  sort = 5 4 0 2 3 1
 *  ie. 2 comes before 3 etc.
 * @version 0.1
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    void dfs(int node , vector<int> adj[] , vector<int> &vis , stack<int> &s){
        vis[node] = 1;
        for(auto child : adj[node]){
            if(vis[child]) continue;
            dfs(child , adj , vis , s);
        }
        s.push(node);
    }
public:
	vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> vis(V , 0);
        stack<int>s;
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                dfs(i , adj , vis , s);
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
	}
};


// will be using indegree vector
// add nodes with indegree 0 first 

class SolutionBFS{
public:
	vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> inDig(V , 0);

        for(int i = 0 ; i < V ; i++){
            for(auto it : adj[i]){
                inDig[it]++; // get the indegree [node] : [connections]
                             // we are looping connections
            }
        }

        // push in Queue [ nodes with inDegree zero ]
        queue<int> q;
        for(int i = 0 ; i < V ; i++){
            if(inDig[i] == 0){
                q.push(i);
            }
        }

        // BFS
        vector<int> ans;
        while(!q.empty()){
            int top = q.front();
            q.pop();

            ans.push_back(top);
            
            for(auto it : adj[top]){
                inDig[it]--; // reduce indegree every time we visit the node
                if(inDig[it] == 0){
                    //bfs it
                    q.push(it);
                }
            }
        }
        return ans;
	}
};