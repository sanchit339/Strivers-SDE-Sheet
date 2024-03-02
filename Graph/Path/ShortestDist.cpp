#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> dist(N , 1e9);

        dist[src] = 0;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int top = q.front();
            q.pop();

            for(auto it : adj[top]){
                if(dist[top] + 1 < dist[it]){
                    dist[it] = dist[top] + 1;
                    q.push(it);
                }
            }
        }

        // now as per the question
        vector<int> ans(N , -1);
        for(int i = 0 ; i < N ; i++){
            if(dist[i] != 1e9){
                ans[i] = dist[i];
            }
        }

        return ans;
    }
};