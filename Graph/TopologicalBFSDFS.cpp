#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    void dfs(int node , vector<int> adj[] , vector<int> &vis , stack<int> &s){
        vis[node] = 1;
        for(auto child : adj[node]){
            if(vis[child]) continue;
            dfs(child , adj , vis , s);
        }
        s.push(node);
    }
public:
	vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> vis(V , 0);
        stack<int>s;
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                dfs(i , adj , vis , s);
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
	}
};


class SolutionBFS{
public:
	vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> inDig(V , 0);

        for(int i = 0 ; i < V ; i++){
            for(auto it : adj[i]){
                inDig[it]++;
            }
        }

        // push in Queue
        queue<int> q;
        for(int i = 0 ; i < V ; i++){
            if(inDig[i] == 0){
                q.push(i);
            }
        }

        // BFS
        vector<int> ans;
        while(!q.empty()){
            int top = q.front();
            q.pop();

            ans.push_back(top);
            
            for(auto it : adj[top]){
                inDig[it]--;
                if(inDig[it] == 0){
                    //bfs it
                    q.push(it);
                }
            }
        }
        return ans;
	}
};