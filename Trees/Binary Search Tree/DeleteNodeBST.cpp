/**
 * @file DeleteNodeBST.cpp
 * 
 * @brief > Search it and connect it to right of the Deep tree
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL; // base case 

        // if we have to delete "root node" extra condition
        if(root -> val == key){
            return helper(root);
        }
        
        TreeNode* dummy = root;
        // Search AND Delete
        while(root != NULL){
            if(root -> val > key){
                if(root -> left != NULL && root -> left -> val == key){
                    root -> left = helper(root -> left);
                    break;
                }
                else{
                    root = root -> left;
                }
            }
            else{
                if(root -> val < key){
                    if(root -> right != NULL && root -> right -> val == key){
                        root -> right = helper(root -> right);
                        break;
                    }
                    else{
                        root = root -> right;
                    }
                }
            }
        }
        return dummy;
    }
        TreeNode* helper(TreeNode* root){
            // check left right NULL
            if(root -> left == NULL)
                return root -> right;
            else if(root -> right == NULL)
                return root -> left;
            
            // Attach Other Subtree
            TreeNode* rightChild = root -> right; // Store
            // find right
            TreeNode* lastRight = FindRight(root -> left);
            lastRight -> right = rightChild;

            // join it 
            return root -> left;
        }

        TreeNode* FindRight(TreeNode* root){
            if(root -> right == NULL)
                return root;
            return FindRight(root -> right);
        }
};