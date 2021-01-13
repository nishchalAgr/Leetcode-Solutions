#-------------------------------------------------------------
# Author: Nishchal Agrawal
# Problem URL: https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/787/
#
# Psuedocode:
#	recursively iterate through the tree using post-order traversal, keeping track of the current depth n
# 		if n-th list doesn't exist, initialize it
#               if n is even, append the current nodes value to the end of the n-th list
#		else if n is odd, insert the current nodes value to the beginning of the n-th list 
#
# Runtime: Beats 98.68% of Python Submissions
#-------------------------------------------------------------


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        acc = []
        self.helper(root, acc, 0)
        return acc
        
    def helper(self, root, acc, index):
        
        if root is None:
            return
        
        if index == len(acc):
            acc.append([root.val])
        else: 
            if index % 2 == 0:
                acc[index].append(root.val)
            else :
                acc[index].insert(0, root.val)
        
    
        self.helper(root.left, acc, index + 1)
        self.helper(root.right, acc, index + 1)
            
