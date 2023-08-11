/**
 * @file SymmetricMirror.cpp
 * 
 * @brief Left -> right , right -> left
 * 
 * @date 2023-08-11
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
    bool isSymmetric(TreeNode* root) {
        return root == NULL || checkSym(root -> left , root -> right);
    }

    bool checkSym(TreeNode* left , TreeNode* right){
        // base case
        if(left == NULL || right == NULL)
            return left == right;

        // other case
        if (left -> val != right -> val) return false;

        return(checkSym(left -> left , right -> right) &&
            checkSym(left -> right , right -> left)    
        ); // 
    }
};