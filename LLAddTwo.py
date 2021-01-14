#------------------------------------------
# Author: Nishchal Agrawal
# Problem URL: https://leetcode.com/explore/interview/card/top-interview-questions-medium/107/linked-list/783/ 
#
# Pseudocode:
#	let carry = 0
# 	Iterate through value i, j in l1, l2:
# 		let val = i + j + carry
#		if val >= 10:
#			val = val - 10
#			carry = 1
#		else:
#			carry = 0
#		
#		create new node in final list and set value to val
#
# Runtime  (56ms): Beat 83.88% of all python submissions
# Memory (13.5MB): Beat 47.27% of all python submissions 
#------------------------------------------

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        temp1 = l1
        temp2 = l2
        ans = ListNode()
        head = ans
        
        carry = 0

        while temp1 is not None or temp2 is not None:
            
            val_1 = 0
            val_2 = 0
            
            if temp1 is not None:
                val_1 = temp1.val
                temp1 = temp1.next
            
            if temp2 is not None:
                val_2 = temp2.val
                temp2 = temp2.next
           
            add_val = val_1 + val_2 + carry
            
            if add_val >= 10:
                add_val = add_val - 10
                carry = 1
            else:
                carry = 0
            
            ans.val = add_val
            if temp1 is None and temp2 is None:
                if carry == 1:
                    ans.next = ListNode()
                    ans.next.val = 1
                return head
            ans.next = ListNode()
            ans = ans.next
        
            
