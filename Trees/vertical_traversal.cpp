/**
 * @file vertical_traversal.cpp
 * @author your name (you@domain.com)
 * @brief DataStructure
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // col , level , nodes 
        map<int,map<int,multiset<int>>> nodes;
        // use Queue Data-Structure
        queue<pair<TreeNode * , pair < int , int > > > q;

        q.push({root, {0 , 0}}); // start itr
        
        while (!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode * node = p.first;
            int x = p.second.first , y = p.second.second;
            nodes[x][y].insert(node -> val);

            if(root -> left){
                q.push({node -> left , {x - 1 , y + 1}}); // traverse nodes
            }
            if(root -> right){
                q.push({node -> right , {x + 1 , y + 1}});
            }
        }
        
        // over Now Final answer
        vector<vector<int>> ans;

        for(auto p : nodes){ // level wise
            vector<int> temp; // create a column at each col . insert all multiset
            for(auto it : p.second){ // p.second = int(y) & multiset too
                temp.insert(temp.end() , it.second.begin() , it.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
