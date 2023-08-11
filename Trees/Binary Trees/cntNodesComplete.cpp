/**
 * @file cntNodesComplete.cpp
 * 
 * @brief With LogN ^2 TC and LogN space 1 + (l C) + (R C) worst case logN 2
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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = HeightLeft(root);
        int rh = HeightRight(root);

        if(lh == rh) return (1 << lh) - 1; // 2 ^ n - 1

        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }

    int HeightLeft(TreeNode* node){
        int cnt = 0;
        while(node){
            cnt++;
            node = node -> left;
        }
        return cnt;
    }
    int HeightRight(TreeNode* node){
        int cnt = 0;
        while(node){
            cnt++;
            node = node -> right;
        }
        return cnt;
    }
};