/*
************************************************************************
Written By: Nishchal Agrawal
Problem URL: https://leetcode.com/problems/rotate-list/

Note: This is my first solution to Rotate List. RotateList2.cpp contains a faster solution to the problem

General Approach:
    Find the len of the linked list
    Iterate through the list to set a pointer at the (len - k)th node and (len - k - 1)th node
    Move the section of the list between (len - k)th node and the (len - 1)th node to the beginning

Submission Metrics:
    Time:   12ms (25.70% of .cpp submissions)
    Memory: 11.2MB (56.68%)
************************************************************************
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (k == 0 || head == nullptr || head->next == nullptr) return head;
        
        ListNode* prev;
        ListNode* current = head;
        ListNode* newHead = nullptr;
        
        int len = length(head);
        int i = 0;
        k = k % len;
        
        if (k == 0) return head;
        
        while (current != nullptr) {
            
            if (i == len - k) newHead = current;
            else if (newHead == nullptr) prev = current;    
            
            i++;            
            if (current->next == nullptr) break;
            current = current->next;
        }
        
        prev->next = nullptr;
        current->next = head;
        head = newHead;
        
        return head;
    }
    
    int length(ListNode* head) {
        
        ListNode* current = head;
        
        int i = 0;
        
        while (current != nullptr) {
            
            current = current->next;
            i++;
        }
        
        return i;
    }
};