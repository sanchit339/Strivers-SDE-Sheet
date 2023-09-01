/**
 * @file Main.cpp
 * @author ATCoder DP Contest
 * 
 * @brief DP 1 and 1 _ 1 step 
 * 
 * @version 0.1
 * @date 2023-08-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
class Solution{
private:
    Node * reverse(Node* head){
        Node* curr = head , *prev = NULL , *next = NULL;
        while (head){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    Node *compute(Node *head){
        Node* temp = reverse(head);
        int maxi = temp -> data;
        Node *temp2 = temp;
        while(temp){
            if(temp -> next -> data > maxi){
                maxi = temp -> data;
                temp = temp -> next;
            }
            else{
                temp -> next = temp -> next -> next;
            }
        }
        return reverse(temp2);
    }
};
