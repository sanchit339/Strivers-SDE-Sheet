/**
 * @file MaxSumPath.cpp
 * @author Striver
 * @brief Just Like Max Height return max sum
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

class Solution {
private:
    int findMaxLength(TreeNode *root , int & maxi){
        if(root == NULL) return 0;

        int lh = max(0 , findMaxLength(root -> left , maxi)); // ignore -ve path length
        int rh = max(0 , findMaxLength(root -> right , maxi));

        // "n" diagram logic
        maxi = max(maxi , root -> val + (lh + rh)); // for subTree to Update the maxiMum
        return (root -> val + max(lh , rh));
    } 
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;

        findMaxLength(root , maxi);

        return maxi;
    }
};