
/**
 * @file Merge2LinkedList.cpp
 * @author Striver (https://leetcode.com/problems/merge-two-sorted-lists/)
 * @brief 
 * @version 0.1
 * @date 2023-09-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1 -> val > l2 -> val){
            swap(l1 , l2);
        }

        ListNode* head = l1;
        while(l1 != NULL && l2 != NULL){
            ListNode* tmp = NULL;
            
            while(l1 != NULL && l1 -> val <= l2 -> val){
                tmp = l1 ; 
                l1 = l1 -> next;
            }

            tmp->next = l2; 
            // now swap them 
            swap(l1 , l2);
        }
        return head;
    }
};