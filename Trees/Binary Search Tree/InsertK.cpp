/**
 * @file InsertK.cpp
 * 
 * @brief  > Call recursion for each subTree
 * 
 * @date 2023-08-11
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
    TreeNode* insertIntoBST(TreeNode* node, int val) {
        if(node == NULL){
            node = new TreeNode(val);
            return node;
        }
        else if(val > node -> val){
            node -> right = insertIntoBST(node -> right , val);
        }
        else if(val < node -> val){
            node -> left = insertIntoBST(node -> left , val);
        }
        return node;
    }
};