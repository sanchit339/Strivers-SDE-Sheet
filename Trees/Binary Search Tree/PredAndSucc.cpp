/**
 * @file PredAndSucc.cpp
 * 
 * @brief > Write Diff Function 
 * 
 * @date 2023-08-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "bits/stdc++.h"
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};


class Solution{
private:
    void Succ(Node* root , Node* &suc , int key){
        if(root == NULL) return;
        
        while(root){
            if(root -> key > key){
                suc = root;
                root = root -> left;
            } 
            else{
                root = root -> right;
            }
        }
    }
private:
    void Pred(Node* root , Node* &pre , int key){
        if(root == NULL) return;
        
        while(root){
            if(root -> key < key){
                pre = root;
                root = root -> right;
            } 
            else{
                root = root -> left;
            }
        }
    }
public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
        // Your code goes here
        Pred(root , pre , key);
        Succ(root , suc , key);
    }
};

//{ Driver Code Starts.
