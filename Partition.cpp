/*
---------------------------------------------------------------------------------------------
Written By: Nishchal Agrawal
Problem URL: https://leetcode.com/problems/partition-list/

General Approach:
    iterate along the list:
        if current node is less than target:
            if the insert pointer is not set and the next node is greater than the target:
                make the insert pointer point to the current node
            else if the insert pointer is set:
                move the current node to directly after the insert pointer

Leetcode Submission Metrics (May 25, 2020):
    Runtime: 4ms (91.88% percentile of .cpp submissions)
    Memory:  10.2MB (13.49% percentile)
---------------------------------------------------------------------------------------------
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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* temp = head;
        ListNode* insert = nullptr;
        ListNode* prev;
        
        if (head == nullptr || head->next == nullptr) return head;
        
        while (temp != nullptr) {
            
            if (temp->val >= x) {
                
                if (insert == nullptr && temp->next != nullptr && temp->next->val < x) {
                    
                    ListNode* y = temp->next;
                    temp->next = y->next;
                    y->next = head;
                    head = y;
                    insert = y;
                }
                
                prev = temp;
            }
            
            else if (temp->val < x) {
                
                if (insert == nullptr && temp->next != nullptr && temp->next->val >= x) {
                    
                    insert = temp;
                }
                
                else if (insert != nullptr){
                    
                    prev->next = temp->next;
                    temp->next = insert->next;
                    insert->next = temp;
                    insert = insert->next;
                    temp = prev;
                }
            }
                        
            temp = temp->next;
        }
        
        return head;
    }
};