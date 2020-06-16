/*************************************************
Author: Nishchal Agrawal
Problem URL: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3356/

General Solution:
Binary search through the array until target is found or until start and end pointers are adjacent

Submission Metrics (4/16/2020):
Time: 8ms (88.61% percentile of cpp submissions)
Memory: 9.7MB (47.01%)
*************************************************/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int start = 0;
        int end = nums.size() - 1;
        int mid = (start + end) / 2;
        
        while (end > start) {
            
            if (end - start == 1) {
                
                if (target > nums[end]) return end + 1;
                if (target > nums[start]) return end;
                if (target < nums[start]) return start;
            }
            if (nums[mid] == target) return mid;
            
            if (nums[mid] > target) {
                
                end = mid;
                mid = (start + end) / 2;
            }
            
            else if (nums[mid] < target) {
                
                start = mid;
                mid = (start + end) / 2;
            }
        }
        
        return target > nums[start] ? 1 : 0;
    }
};