/**
 * @file same_Tree.cpp
 * @author Striver
 * @brief Check any Traversal from same node 
 * @version 0.1
 * @date 2023-08-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include<bits/stdc++.h>
using namespace std;


//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // call will the nodes
        if(p == NULL || q == NULL){
            return p == q ;
        }

        return (p -> val == q -> val && isSameTree(p -> right , q -> right) && isSameTree(p -> left , q -> left));
    }
};