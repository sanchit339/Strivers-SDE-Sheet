/**
 * @file KthLargest.cpp
 * @author Sanchit
 * 
 * @brief > Use Reverse InOrder
 * 
 * @date 2023-08-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        data = data;
        left = right = NULL;
    }
};


// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
private:
    void InOrderReverse(Node* root, int& k, int& count, int& result) {
        if (root == nullptr) return;

        InOrderReverse(root->right, k, count, result);
        count++;
        
        if (count == k) {
            result = root->data;
            return;
        }
        
        InOrderReverse(root->left, k, count, result);
    }

public:
    int kthLargest(Node *root, int K)
    {
        int count = 0;
        int result = -1; // Initialize with a value that doesn't exist in the tree
        InOrderReverse(root, K, count, result);
        return result;
    }
};