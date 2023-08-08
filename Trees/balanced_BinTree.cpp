/**
 * @file balanced_BinTree.cpp
 * @author Striver
 * @brief Return -1 logic
 * @version 0.1
 * @date 2023-08-08
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
    bool isBalanced(TreeNode* root) {
        return checkBal(root) != -1; // if -1 not balanced        
    }

    int checkBal(TreeNode * root){
        if(root == NULL) return 0;

        int lh = checkBal(root -> left);
        if(lh == -1) return -1;

        int rh = checkBal(root -> right);
        if(rh == -1) return -1;

        if(abs(lh - rh) > 1) return -1;

        return max(lh , rh) + 1;
    }
};