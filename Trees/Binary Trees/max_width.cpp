/**
 * @file max_width.cpp
 * @author Striver
 * 
 * @brief Max Number of nodes in a Level btn two nodes
 *        (2 * i + 1) just remeber it  
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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        int ans = 0;
        queue<pair< TreeNode*, int >> q;
        q.push({root , 0});

        while(!q.empty()){
            int size = q.size();
            int mini = q.front().second; // first element of the lev will be the min

            int first , last;
            for(int i = 0 ; i < size ; i++){
                int curr = q.front().second - mini; // just to avoid int overflow
                TreeNode* front = q.front().first;
                q.pop();
                if(i == 0) first = curr;
                if(i == size - 1) last = curr;

                if(front -> left){
                    q.push({front -> left , curr * 2 + 1});
                }
                if(front -> right){
                    q.push({front -> right , curr * 2 + 2});
                }
            }
            ans = max(ans , last - first + 1);
        }
        return ans;
    }
};