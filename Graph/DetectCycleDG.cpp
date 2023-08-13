#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool dfs(int node , vector<int> adj[] , vector<int> &vis ,  vector<int> &path){
        vis[node] = 1;
        path[node] = 1;
        for(auto child : adj[node]){
            if(!vis[child]){
                if(dfs(child , adj , vis , path) == true) return true;
            }
            else if(path[child]){
                return true;
            }
        }
        path[node] = 0; // backtracking
        return false;
    }
public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V , 0);
        vector<int> path(V , 0);

        for(int i = 0 ; i < V ; ++i){
            if(!vis[i]){
                if(dfs(i , adj , vis , path) == true) return true;
            }
        }
        return false;
    }
};