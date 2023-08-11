/**
 * @file CreateMirror.cpp
 * 
 * @brief Traverse and Swap
 *  
 * @date 2023-08-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(node == NULL) return;
        
        if(node -> left == NULL && node -> right == NULL) return;
        
        mirror(node -> left);
        mirror(node -> right);
        
       // swap function
       Node* temp = node -> left;
       node -> left = node -> right;
       node -> right = temp;
    }
};