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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q ){
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root -> left , p , q);
        TreeNode* right = lowestCommonAncestor(root -> right , p , q);

        if(left == NULL)
            return right;
        
        if(right == NULL)
            return left;
        
        return root; // at last of the root node
    }
};