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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *>s;
        vector<int>ans;

        if(root == NULL) return ans;
        s.push(root);
        while(!s.empty()){
            root = s.top();
            s.pop();
            ans.push_back(root -> val);
            if(root -> right) s.push(root -> right); // LIFO
            if(root -> left) s.push(root -> left);
        }
        return ans;
    }
};