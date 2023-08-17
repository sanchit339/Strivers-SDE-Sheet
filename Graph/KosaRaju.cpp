/**
 * @file KosaRaju.cpp
 * @author striver
 * 
 * @brief > Used to find the Strongly connected components
 *        > DFS
 *        > put in stack
 *        > reverse the edges       
 *        > DFS it and cnt While St.empty()
 *   
 * @version 0.1
 * @date 2023-08-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    void dfs(int node , vector<vector<int>> &adj , vector<int> &vis , stack<int> &st){
        vis[node] = 1;
        for(auto child : adj[node]){
            if(vis[child]) continue;
            dfs(child , adj , vis , st);
        }
        st.push(node);
    }
private:
    void SCCDFS(int node , vector<vector<int>> & adjT , vector<int> &vis){
        vis[node] = 1;
        for(auto child : adjT[node]){
            if(vis[child]) continue;
            SCCDFS(child , adjT , vis);
        }
    }
public:
    int kosaraju(int V, vector<vector<int>>& adj){
        vector<int> vis(V , 0);
        stack<int> st;

        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                dfs(i , adj , vis , st);
            }
        }
        // the stack has been filled RN

        // Reverse the nodes
        vector<vector<int>> adjT; // transpose 
        for(int i = 0 ; i < V ; i++){
            vis[i] = 0;
            for(auto it : adj[i]){
                adjT[it].push_back(i);
            }
        }

        // call dfs again 
        int SCC = 0;
        
        // using Stack call the new DFS
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                SCC++;
                SCCDFS(node , adjT , vis);
            }
        }
        return SCC;
    }
};