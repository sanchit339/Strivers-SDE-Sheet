/**
 * @file BottomView.cpp
 * @author Sanchit
 * @brief Last Node in Map
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


class Solution {
  public:
    vector <int> bottomView(Node *root){
        map<int , int> m;
        queue<pair<Node * , int >> q; 

        q.push({root , 0});
        while(!q.empty()){
            auto top = q.front();
            q.pop();

            Node * node = top.first;
            int x = top.second;
            
            m[x] = node -> data;

            if(node -> left)
                q.push({node -> left , x - 1});
            
            if(node -> right)
                q.push({node -> right , x + 1});
        }

        vector<int>ans;
        for(auto it : m){
            ans.push_back(it.second);
        }
        return ans;
    }
};