# ---------------------------------------------
# Author: Nishchal Agrawal
# Email: nishchalagrawal123@gmail.com
# 
# Problem URL: https://leetcode.com/explore/interview/card/top-interview-questions-medium/107/linked-list/784/
#
# Pseudocode:
# 	mark node 0 as D
# 	mark node 1 as E
#  	for each node N in list after index 1:
#		if index is odd:
#			insert N directly after D
#			iterate D
#		else:
#			insert N directly after E
#			iterate E
# 
# Runtime: Beats 89.20% of python submissions
# Memory : Beats 86.61% of python submissions
# ---------------------------------------------

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head
        
        orig = head
        odd = head
        even = head.next
        head = even.next
        
        isOdd = True
        
        while head is not None:
            if isOdd:
                temp = head
                even.next = head.next
                even = even.next
                head = head.next
                temp.next = odd.next
                odd.next = temp
                odd = odd.next
                isOdd = False
            else:
                head = head.next
                isOdd = True
                
        return orig
