//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
	bool bfs(int start , vector<int>graph[] , vector<int> &color){
        queue<int>q;
        q.push(start);

        color[0] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                // if Not colored
                if(color[it] == -1){
                    color[it] = !color[node]; // color oppo to node
                    q.push(it);
                }
                // if cannot color (parent == child)
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(int V, vector<int>adj[]){
        vector<int> color (V , -1);
	    for(int i = 0; i < V; i++){ // cycles can be there so
	        if(color[i] == -1){
	            if(bfs(i, adj, color) == false) return false;
	        }
	    }
        return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends