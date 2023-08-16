//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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

            for(auto child : adj[u]){ // 0 , 1 , 2 // 0 is used as index
                int child_wt = child[1];
                int v = child[0];
                if(!vis[v]){
                    pq.push({child_wt , v});
                }
            }
        }

        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends