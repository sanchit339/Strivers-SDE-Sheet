/**
 * @file LargestBST.cpp
 * @author Striver
 * @brief Was A Bottom up Approch (size , mini , maxi)
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

class NodeValue{
public:
    int maxi , mini , size;
    NodeValue(int mini , int maxi , int size){
        this -> maxi = maxi;
        this -> mini = mini;
        this -> size = size;
    }
};

// post order traversal
class Solution {
private:
    NodeValue largestBST(TreeNode* root){
        // Empty BST with size 0
        if(!root){
            return NodeValue(INT_MAX , INT_MIN , 0);
        }

        auto left = largestBST(root -> left);
        auto right = largestBST(root -> right);

        // check left node maxi > ahe and right mini <
        if(left.maxi < root -> val && root -> val < right.mini ){
            // so , it is a BST
            // storing min , max , size of that BST
            return NodeValue(min(root -> val , left.mini) , max(root -> val , right.maxi) , left.size + right.size + 1); 
        }
        return NodeValue(INT_MIN , INT_MAX , max(left.size , right.size));
    }
public:
    int maxSumBST(TreeNode* root) {
        return largestBST(root).size;
    }
};