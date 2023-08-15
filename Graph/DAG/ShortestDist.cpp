#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        // for shortest we prefer BFS
        vector<pair<int,int>> graph[N]; // U -> V {v , wt}
        for(int i = 0 ; i < M ; i++){
            int x = edges[i][0];
            int y = edges[i][1];
            int wt = edges[i][2];

            graph[x].push_back({y , wt});
        }

        queue<int>q;
        vector<int> dis(N , INFINITY);

        dis[0] = 0;
        while(!q.empty()){
            int top = q.front();
            q.pop();

            for(auto it : graph[top]){
                int v = it.first;
                int wt = it.second;

                if(dis[top] + wt < dis[v]){
                    dis[v] = dis[top] + wt;
                    q.push(v);
                }
            }
        }
        return dis;
    }
};