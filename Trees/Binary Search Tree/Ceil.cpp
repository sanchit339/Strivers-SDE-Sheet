/**
 * @file ceil.cpp
 * 
 * @brief Just Greater or Equal 
 * 
 * @date 2023-08-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    // Your code here
    int Ceil = -1;
    while(root){
        if(root -> data == input){
            Ceil = root -> data;
            return Ceil;
        }
        
        // only one condition
        if(input > root -> data){
            root = root -> right;
        }
        else{
            Ceil = root -> data; // update the ceil
            root = root -> left;
        }
    }
    return Ceil;
}
