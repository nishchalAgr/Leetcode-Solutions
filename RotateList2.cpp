/*
************************************************************************
Written By: Nishchal Agrawal
Problem URL: https://leetcode.com/problems/rotate-list/

Note: This is my revised solution to Rotate List. RotateList1.cpp contains a slightly more memory efficient solution

General Approach:
    Find the len of the linked list, and assign each node to an element in a vector
    Use the vector to set a pointer at the (len - k)th node and (len - k - 1)th node
    Move the section of the list between (len - k)th node and the (len - 1)th node to the beginning

Submission Metrics:
    Time:   8ms (76.91% of .cpp submissions)
    Memory: 11.6MB (5.18%)
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
        
        vector<ListNode*> pointerList;
        
        if (k == 0 || head == nullptr || head->next == nullptr) return head;
        
        ListNode* current = head;        
        int i = 0;
        
        while (current != nullptr) {
            
            pointerList.push_back(current);
            current = current->next;
            i++;
        }
        
        k = k % i;
        if (k == 0) return head;
        
        pointerList[i - k - 1]->next = nullptr;
        pointerList[i - 1]->next = head;
        head = pointerList[i - k];
        
        return head;
    }
};