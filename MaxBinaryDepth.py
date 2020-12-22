# -------------------------------
# Author: Nishchal Agrawal
# Problem URL: https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3551/

# My approach:
#     - Recursively traverse the binary depth tree, iterating an accumulator for each branching path
#     - Path returns accumulator once a leaf node is reached
#     - The largest accumulator is returned as the answer 

# Runtime: Beats 82.70% of python submissions
# Memory:  Beats 94.71% of python submissions
# -------------------------------

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        
        h1 = self.helper(root.left, 1)
        h2 = self.helper(root.right, 1)
        
        if h1 > h2: 
            return h1
        return h2
        
    def helper(self, root, acc):
        if root is None:
            return acc
        
        h1 = self.helper(root.left, acc + 1)
        h2 = self.helper(root.right, acc + 1)
        
        if h1 > h2: 
            return h1
        return h2