#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node * left ;
    Node * right ;

    Node(int data){
        val = data;
        Node * left = NULL;
        Node * right = NULL;
    } 
};

class Solution{
    public:
    int maxDepth(Node * root){
        if(root == NULL) return 0;

        int lh = maxDepth(root -> left);
        int rh = maxDepth(root -> right);

        return 1 + max(lh , rh);
    }
};