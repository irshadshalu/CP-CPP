// https://leetcode.com/problems/add-two-numbers

#include<string>
#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        
        int carry = 0;
        ListNode *root, *ptr, *temp;
        root = ptr = NULL;
        while(l1 != NULL || l2 != NULL || carry > 0) {
            int a = (l1==NULL)? 0: l1->val;
            int b = (l2==NULL)? 0: l2->val;
            int t = carry + a + b;
            carry = t / 10;
            
            temp = new ListNode(t % 10);
            if(root == NULL) root = ptr = temp;
            else { ptr -> next = temp; ptr = temp; }
            
            if(l1) l1 = l1 -> next; 
            if(l2) l2 = l2 -> next;
        }
        return root;
    }
};