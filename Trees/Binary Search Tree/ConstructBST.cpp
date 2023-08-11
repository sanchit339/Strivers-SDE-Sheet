/**
 * @file ConstructBST.cpp
 * @author Sanchit
 * 
 * @brief MainTain Upper Bound
 * 
 * @version 0.1
 * @date 2023-08-11
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
    TreeNode* constructBST(vector<int>& v , int &i , long long int maxi){
        if(i == v.size() || v[i] > maxi) return NULL;
        TreeNode* node = new TreeNode(v[i++]);
        
        // traverse 
        node -> left = constructBST(v , i , node -> val);
        // maintain Upper Bound
        node -> right = constructBST(v , i , maxi);
        
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0; // to iterate vector
        long long int maxi = LLONG_MAX;
        return constructBST(preorder , i , maxi);
    }
};