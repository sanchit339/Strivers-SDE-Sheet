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
    bool checkBST(TreeNode* root , long long int mini , long long int maxi){
        if(root == NULL) return true;
        if(root -> val > maxi && root -> val < mini) return false;

        return checkBST(root -> left , mini , root -> val) 
        && checkBST(root -> right , root -> val , maxi);
    }
public:
    bool isValidBST(TreeNode* root) {
        long long int mini = LLONG_MIN , maxi = LLONG_MAX;
        return checkBST(root , mini , maxi);
    }
};