/**
 * @file CourseDFS.cpp
 * @author your name (you@domain.com)
 * 
 * @brief > Kahns algo
 * 
 * @version 0.1
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// Detect cycle in Directed Graph

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];
        for(auto it : prerequisites){
            int x = it[0] , y = it[1];
            adj[y].push_back(x);
        }

        vector<int> inDeg(numCourses , 0);
        for(int i = 0 ; i < numCourses ; ++i){
            for(auto it : adj[i]){
                inDeg[it]++;
            }
        }

        queue<int>q;
        for(int i = 0 ; i < numCourses ; ++i){
            if(inDeg[i] == 0)
                q.push(i);
        }

        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ++cnt;
            for(auto child : adj[node]){
                --inDeg[child];
                if(inDeg[child] == 0)
                    q.push(child);
            }
        }
        if(cnt == numCourses) return true; //  courses can be completed
        return false;
    }
};