#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create adj list;
        vector<int> adj[numCourses];
        for(auto it : prerequisites){
            int x = it[0] , y = it[1];
            adj[x].push_back(y);
        }

        // as we have to maintain order 
        vector<int> inDig(numCourses , 0);
        for(int i = 0 ; i < numCourses ; ++i){
            for(auto it : adj[i]){
                inDig[it]++;
            }
        } 

        // push in Queue
        queue<int> q;
        for(int i = 0 ; i < numCourses; i++){
            if(inDig[i] == 0){
                q.push(i);
            }
        }

        // BFS
        int cnt = 0;
        while(!q.empty()){
            int top = q.front();
            q.pop();

            cnt++;
            
            for(auto it : adj[top]){
                inDig[it]--;
                if(inDig[it] == 0){
                    //bfs it
                    q.push(it);
                }
            }
        }
        if(cnt == numCourses) return true;
        return false;
    }
};