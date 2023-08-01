//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfsHelp(int node , vector<int>&ans , vector<int> &vis , vector<int> adj[]){
        
        // before entering dfs mark visited
        vis[node] = true;
        
        ans.push_back(node);
        for(auto child : adj[node]){
            if(vis[child]) continue;
            dfsHelp(child , ans , vis , adj);
        }
    }
    
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        // we need helper function
        vector<int>ans;
        
        vector<int>vis(V,0);
        
        for(int i = 0 ; i < V ; ++i){
            if(!vis[i]){
                dfsHelp(i , ans , vis , adj); // for each i run dfs
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends