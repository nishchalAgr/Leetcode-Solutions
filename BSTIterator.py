# -------------------------------
# Author: Nishchal Agrawal
# Problem URL: https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/570/week-2-december-8th-december-14th/3560/

# My approach:
#   - When consructor is called, perform in order traversal and store nodes in array
#   - When next() is called, return array entry at global index, and then iterate global index
#   - When hasNext() is called, return true if global index is less than length of array

# Runtime: Beats 65.46% of python submissions
# Memory:  Beats 74.81% of python submissions
# -------------------------------

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator(object):
    
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.btsList = []
        self.initList(root)
        print(self.btsList)
        self.index = 0
        
    def initList(self, root):
        
        if root.left is not None:
            self.initList(root.left)
            
        self.btsList.append(root.val)
        
        if root.right is not None:
            self.initList(root.right)
        
    def next(self):
        """
        :rtype: int
        """
        old = self.index
        self.index += 1
        return self.btsList[old]

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.index < len(self.btsList)
        


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()