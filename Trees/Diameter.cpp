/**
 * @file Diameter.cpp
 * @author Striver
 * 
 * @brief Maintain Maxi
 * 
 * @version 0.1
 * @date 2023-08-08
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
    int maxDia(TreeNode* root , int & maxi){
        if(root == NULL) return 0;

        int lh =maxDia (root -> left , maxi);
        int rh = maxDia (root -> right , maxi);

        maxi = max(maxi , rh + lh);

        return max(lh , rh) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;

        maxDia( root , maxi); // it will return some value but we just want the maxi of it 

        return maxi;
    }
};