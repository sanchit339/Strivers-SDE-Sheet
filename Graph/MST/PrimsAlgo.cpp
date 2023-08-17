/**
 * @file PrimsAlgo.cpp
 * @author Striver
 * 
 * @brief > Vis , MIN Span Vector {To maintian Edges} , Priority Queue
 *        > Start from source nOde 0   
 *          
 *        > TC E Log E  
 * @version 0.1
 * @date 2023-08-16
 */

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int spanningTree(int V, vector<vector<int>> adj[]){

        // we have to return mini sum
        vector<int> vis(V , 0);
        // vector<pair<int,int>> Nodes;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;

        pq.push({0 , 0});
        int sum = 0;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            
            int wt = node.first;
            int u = node.second;

            if(vis[u]) continue;

            vis[u] = 1;
            sum += wt;

            for(auto child : adj[u]){
                int child_wt = child[2];
                int v = child[1];
                if(!vis[v]){
                    pq.push({child_wt , v});
                }
            }
        }

        return sum;
    }
};