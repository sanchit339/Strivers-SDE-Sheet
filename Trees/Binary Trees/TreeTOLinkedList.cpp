/**
 * @file TreeTOLinkedList.cpp
 * @author Striver
 * @brief Just Like Delete Node in tree (Optimal Approch)   
 *        1 approch Recursion Solve from right 
 *        2 Using Stack (Push left , then right)  
 * @version 0.1
 * @date 2023-09-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr -> left != NULL){
                TreeNode* prev = curr -> left;
                while(prev -> right != NULL){
                    prev = prev -> right;
                }
                prev -> right = curr -> right;
                curr -> right = curr -> left;

                curr -> left = NULL; // making null
            }
            curr = curr -> right;
        }
    }
};