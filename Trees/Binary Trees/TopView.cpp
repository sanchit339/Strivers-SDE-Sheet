/**
 * @file TopView.cpp
 * @author Striver
 * @brief Use Lines First node of each line will be the top view
 * @version 0.1
 * @date 2023-08-08
 */
#include<bits/stdc++.h>
using namespace std;


//  * Definition for a binary tree node.
struct Node {
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root){ // store only single node of each line ( -1 , 1 , 0 , 1)
        map<int , int > m; // store line , node
        queue<pair<Node * , int >> q;

        q.push({root , 0});
        while (!q.empty()){
            auto top = q.front();
            q.pop();
            Node * TreeNode = top.first;
            int line = top.second;
            // if not preset then push
            if(m.find(line) == m.end()) 
                m[line] = TreeNode -> data;

            if(TreeNode -> left)
                q.push({TreeNode -> left , line - 1});
            
            if(TreeNode -> right)
                q.push({TreeNode -> right , line + 1});
        }

        vector<int> ans;
        
        for(auto it : m){
            ans.push_back(it.second);
        }
        return ans;
    }
};


class Solution{
    private:
        void dfs(int node , vector<int> adj[] , vector<int> vis){
            vis[node] = 1;
            for(auto child : adj[node]){
                if(vis[child]) continue;
                dfs(child , adj , vis);
            }
        }

        void bfs(int node , vector<int> adj[] , vector<int> vis){
            queue<int>q;
            q.push(node);
            vis[node] = 1;
            while(!q.empty()){
                int top = q.front();
                q.pop();

                for(auto child : adj[top]){
                    if(!vis[child]){
                        q.push(child);
                        cout << child << " ";
                    }
                }
            }
        }
};