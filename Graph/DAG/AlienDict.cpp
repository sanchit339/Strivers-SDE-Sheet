/**
 * @file AlienDict.cpp
 * @author Striver
 * 
 * @brief > Find Relation in Comparision with other
 *        > a   b   c    d 
 *        > a   b   c    a
 *          ||  ||  || (b < a)     ie (d -> b)
 * 
 *        > create a directed graph in order to solve the list smilar to [ course schedule II ]
 * 
 *        > suppose k = 5
 *        > max(string.len()) == 4 that means e is independent 
 *        
 *        > Task is to create a DG [ Directed Graph ]  
 *         
 * @version 0.1
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

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

        for(int i = 0 ; i < N - 1; i++){
            string s1 = dict[i];
            string s2 = dict[i + 1];
            
            int len = min(s1.size() , s2.size());
            for(int ptr = 0 ; ptr < len ; ptr++){
                if(s1[ptr] != s2[ptr]){
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a'); // adj list generation
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