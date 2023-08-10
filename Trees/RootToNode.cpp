/**
 * @file RootToNode.cpp
 * @author Striver 
 * 
 * @brief BackTrack Using pop and return BOOL
 * 
 * @version 0.1
 * @date 2023-08-09
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


struct Node
{
    int data;
    Node* left;
    Node* right;
};

/* The function should print all the paths from root
 to leaf nodes of the binary tree */

void traverse(Node* root , vector<vector<int>> &ans , vector<int> &temp){
    if(root == NULL){
        ans.push_back(temp);
        return;
    }

    temp.push_back(root->data);
    if(root -> left){
        traverse(root -> left , ans , temp);
    }
    if(root -> left){
        traverse(root -> right , ans , temp);
    }

    temp.pop_back();
}

vector<vector<int>> Paths(Node* root)
{
    // Code here
    vector<vector<int>> ans;
    vector<int> temp;
    traverse(root , ans , temp);

    return ans;
}

class Solution{
private:
    bool findPath(TreeNode *root , vector<int> &ans , int x){
        if(root == NULL) return false; // not reached

        ans.push_back(root -> val);

        if(root -> val == x){
            return true;
        }

        if(findPath(root -> left , ans , x) || findPath(root -> right , ans , x))
            return true; // just checking if it totally exists in left / Right

        ans.pop_back();
        return false;
    }
public:
    vector<int> findTraverse(TreeNode * root , int x){ 
        vector<int> ans;
        
        findPath(root , ans , x);

        return ans;
    }
};