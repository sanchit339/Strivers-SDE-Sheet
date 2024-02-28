#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCyclic(int V, vector<int> adj[]){
        // using BFS Kahns Algo
        // IF ans != V return cycle exists

        vector<int> InDig(V , 0);
        for(int i = 0 ; i < V ; i++){
            for(auto it : adj[i]){
                InDig[it]++;
            }
        }

        queue<int>q;
        for(auto it : InDig){
            if(it == 0){
                q.push(it);
            }
        }

        int cnt = 0;
        while(!q.empty()){
            int top = q.front();
            q.pop();

            cnt++;
            for(auto it : adj[top]){
                InDig[it]--;
                if(InDig[it] == 0){
                    q.push(it);
                }
            }
        }

        if(cnt == V) return false;
        return true;
    }
};