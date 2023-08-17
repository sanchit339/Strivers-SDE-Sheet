#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {

        vector<int> dist(V , 1e8);
        dist[S] = 0;
        // till V - 1 nodes

        for(int i = 0 ; i < V - 1 ; ++i){
            for(auto vec : edges){
                int u = vec[0];
                int v = vec[1];
                int wt = vec[2];
                if(dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // fix edges are relaxed again the loop exists
        for(auto vec : edges){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];
            if(dist[u] + wt < dist[v]){
                return {-1};
            }
        }
        return dist;
    }
};