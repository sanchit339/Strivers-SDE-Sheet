/**
 * @file PostOrder2Stack.cpp
 * 
 * @brief > 2 Stack Implementation
 *        > One to Iterate and One to strore the answer  
 * 
 * @date 2023-08-10
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


// iterative PreOder using Stack

// right -> left

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;

        stack<TreeNode*> s1 , s2;

        // start from root node
        s1.push(root);
        while(!s1.empty()){
            root = s1.top();
            s1.pop();
            s2.push(root);

            // push left and right too
            if(root -> left) s1.push(root -> left);
            if(root -> right) s1.push(root -> right);
        }

        while(!s2.empty()){
            root = s2.top();
            s2.pop();
            ans.push_back(root -> val);
        }
        return ans;
    }
};