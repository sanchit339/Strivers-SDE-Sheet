/**
 * @file Right_left_View.cpp
 * @author Striver
 *
 * @brief > Use Recursive Because for itr when at bottom more space is required to just store leaf nodes
 *        > Last line of the iter
 * 
 * @brief Use Reverse Pre Order Traversal
 * 
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

void recursion(Node * root , int height , vector<int> &ans){
    if(root == NULL) return;

    if(ans.size() == height) ans.push_back(root -> data);

    recursion(root -> right , height + 1 , ans);
    recursion(root -> left , height + 1 , ans);
}
vector<int> leftView(Node *root){
    vector<int> ans;
    
    recursion(root , 0 , ans);

    return ans;
}