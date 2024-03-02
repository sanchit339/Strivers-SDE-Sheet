/**
 * @file PQ_Dijkstra.cpp
 * @author Striver 
 * 
 * @brief > cant have the negative weight coz it will keep looping in th PQ 
 *        > inc the weight (the dist)  
 *        > TC = E log(V)  
 * 
 * @version 0.1
 * @date 2024-03-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        vector<int> dist(V , 1e9);
        
        // store dist , src
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq;
        pq.push({0 , S});
        
        dist[S] = 0;
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            for(auto child : adj[node]){
                // in adj node , wt given 
                int wt = child[1];
                int adjNode = child[0];
                
                if(wt + d < dist[adjNode]){
                    dist[adjNode] = wt + d;
                    pq.push({dist[adjNode] , adjNode});
                }
                
            }
        }
        return dist;
    }
};