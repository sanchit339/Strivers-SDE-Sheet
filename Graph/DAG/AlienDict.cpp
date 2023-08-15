#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
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
public:
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];

        for(int i = 0 ; i < N ; i++){
            string s1 = dict[i];
            string s2 = dict[i + 1];
            
            int len = min(s1.size() , s2.size());
            for(int ptr = 0 ; ptr < len ; ptr++){
                if(s1[ptr] != s2[ptr]){
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        vector<int> temp = topoSort(K , adj);

        string ans = "";

        for(auto it : temp){
            ans.push_back(it + 'a');
        }

        return ans;
    }
};