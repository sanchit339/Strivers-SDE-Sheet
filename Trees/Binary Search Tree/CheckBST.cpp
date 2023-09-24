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
    bool solve(TreeNode* root , long long int mini , long long int maxi){
        if(root == NULL) return true;
        if(root -> val >= maxi || root -> val <= mini) return false;

        return solve(root -> left , mini , root -> val) && solve(root -> right , root -> val , maxi);
    }
public:
    bool isValidBST(TreeNode* root) {
        long long int maxi = LLONG_MAX , mini = LLONG_MIN;
        return solve(root , mini , maxi);
    }
};