#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, * right;
};

class Solution {
private:
    bool isleaf(Node* root){
        if(!root->left and !root->right) return true;
        else return false;
    }
private:
    void traverseLeft(Node * root , vector<int> &ans){
        if(!root || (!root -> left && !root -> right)) return; // leaf node eliminate

        ans.push_back(root -> data); // after base case check 

        // if left avaliable
        if(root -> left){
            traverseLeft(root -> left , ans);
        }
        // if not avaliable
        else if(root -> right){
            traverseLeft(root -> right , ans);
        }
    }

    void traverseLeaf(Node * root , vector<int> &ans){
        if(!root) return; // null eleminate

        if( !root -> right && !root -> left){
            ans.push_back(root -> data);
        }

        traverseLeaf(root -> left , ans); // from left side
        traverseLeaf(root -> right , ans);
    }

    void traverseRight(Node * root , vector<int> &ans){

        //base case to eliminate leaf and NULL
        if(!root || (!root -> left && !root -> right)) return;

        if(root -> right ){
            traverseRight(root -> right , ans);
        }
        else if(root -> left){
            traverseRight(root -> left , ans);
        }

        ans.push_back(root -> data);
    }   

public:
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root){
            if(!isleaf(root))
                ans.push_back(root -> data);

            // traverse left tree 
            traverseLeft(root -> left , ans);

            // traverse leaf tree
            traverseLeaf(root , ans);

            // traverse right Tree
            traverseRight(root -> right , ans);
        }
        return ans;
    }
};