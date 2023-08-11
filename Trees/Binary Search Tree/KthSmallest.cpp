/**
 * @file KthSmallest.cpp
 * @author Striver
 * 
 * @brief Just Inorder traerse
 * 
 * @version 0.1
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
private:
    void InOrder(TreeNode* root , int k , int &cnt, int& ans){
        if(root == NULL) return;

        InOrder(root -> left , k , cnt , ans);
        cnt++;
        if(cnt == k) ans = root -> val;
        InOrder(root -> right , k , cnt , ans);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0 , ans = 0;
        InOrder(root , k , cnt , ans);
        return ans;
    }
};