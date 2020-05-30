/*
---------------------------------------------------------------------------------------------
Written By: Nishchal Agrawal

Problem URL: https://leetcode.com/problems/same-tree/

General Approach:
    While performing BFS on both trees, check if each node is equal

Leetcode Submission Metrics (May 25, 2020):
    Runtime: 0ms (100% percentile)
    Memory: 36.6MB (5.75% percentile)
---------------------------------------------------------------------------------------------
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        
        if (p == null && q == null) return true;
        
        else if ((p == null && q != null) || 
                 (p != null && q == null) || 
                 (p.val != q.val)) return false;
         
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}