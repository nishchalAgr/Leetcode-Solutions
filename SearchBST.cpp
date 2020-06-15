/*************************************************
Author: Nishchal Agrawal
Problem URL: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3361/

Submission Metrics:
Time: 60ms (76.35% percentile of cpp submissions)
Memory: 34.9MB (18.09%)
*************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        TreeNode* current = root;
        
        while (current != nullptr) {
            
            if (current->val > val) current = current->left;
            else if (current->val < val) current = current->right;
            else return current;
        }
        
        return nullptr;
    }
};