#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        vector<int> vis(V , 0);
        vector<int> dist(V , 1e9);

        set<pair<int,int>> st;
        st.insert({0 , S});
        dist[S] = 0;

        while(!st.empty()){
            auto top = *st.begin();
            int node = top.second;
            int Ndist = top.first;
            
            st.erase(st.begin());
            
            if(vis[node]) continue;
            vis[node] = 1;
             
            for(auto child : adj[node]){
                int v = child[0];
                int Vdist = child[1];

                if(Ndist + Vdist < dist[v]){
                    dist[v] = Vdist + Ndist;
                    st.insert({dist[v] , v});
                }
            }
        }
        return dist;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // convert to adj
        vector<pair<int,int>> graph[n];
        for(auto vec : times){
            graph[vec[0]].push_back({vec[1] , vec[2]});
        }

    }
};

class Solution{
private:
    const int INF = 1e9;
    const int N = 1e5 + 10;
private:
     int dijkstra(int V, vector<pair<int,int>> graph[] , int S){
        // vector<int> vis(N , 0);
        vector<int> dist(N , INF);

        set<pair<int,int>> st;
        st.insert({0 , S});
        dist[S] = 0;

        while(st.size() > 0){
            auto top = *st.begin();
            int node = top.second;
            int Node_dist = top.first;
            
            st.erase(st.begin());
            
            // if(vis[node]) continue;
            // vis[node] = 1;
             
            for(auto child : graph[node]){
                int child_v = child.first;
                int child_dist = child.second;

                if(dist[node] + child_dist < dist[child_v]){
                    dist[child_v] = dist[node] + child_dist;
                    st.insert({dist[child_v] , child_v});
                }
            }
        }
        int ans = 0;
        for(int i = 1 ; i <= V ; i++){
            if(dist[i] == INF){
                return -1; // cannot received
            }
            ans = max(ans , dist[i]);
        }
        return ans;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // convert to adj
        vector<pair<int,int>> graph[N];
        for(auto vec : times){
            graph[vec[0]].push_back({vec[1] , vec[2]});
        }
        return dijkstra( n , graph , k);
    }
};