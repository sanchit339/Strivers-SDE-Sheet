/**
 * @file SeearchKey.cpp
 * 
 * @brief > TC log2(N)
 * 
 * @version 0.1
 * @date 2023-08-11
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        if(root -> val == val) return root;

        if(root -> val < val)
        {
            return searchBST(root -> right , val);   
        }
        else
        {
            return searchBST(root -> left , val);
        }
    }
};