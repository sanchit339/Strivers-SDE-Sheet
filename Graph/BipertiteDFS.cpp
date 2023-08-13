#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	bool dfs(int node , int col , vector<vector<int>> &graph , vector<int> &color ){
        color[node] = col;
        for(auto child : graph[node]){
            if(color[child] == -1){
                if(dfs(child , !col , graph , color) == false) return false;
            }
            else if(color[child] == col){ // if same color
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph){
        int V = graph.size();
        vector<int> color (V , -1);
	    for(int i = 0; i < V; i++){ // cycles can be there so
	        if(color[i] == -1){
	            if(dfs( i , 0 , graph , color ) == false) return false;
	        }
	    }
        return true;
	}
};