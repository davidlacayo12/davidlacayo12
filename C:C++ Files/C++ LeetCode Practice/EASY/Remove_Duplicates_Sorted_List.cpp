//Problem #83 on Leetcode
//Remove duplicates from a sorted singly-linked list by using recursion

#include <iostream>


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       if(head == nullptr  || head->next == nullptr) {return head;}
       head->next = deleteDuplicates(head->next);
       return (head->val == head->next->val) ? head->next : head;   //ternary operator to decide whether to return new value (no repeat) or skip since repeat value
    }
};