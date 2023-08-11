/**
 * @file ceil.cpp
 * 
 * @brief > Gretest val just smaller than equal to number
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
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

int floor(Node* root, int x) {
    // Code here
    int ans = -1;
    while(root){
        if(root -> data == x){
            ans = root -> data;
            return ans;
        }
        
        if(root -> data > x){
            root = root -> left;
        }
        else{
            ans = root -> data;
            root = root -> right;
        }
    }
    return ans;
}


int floor(Node *root, int x);

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

// } Driver Code Ends


int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;

        cout << floor(root, s) << "\n";
    }
}
