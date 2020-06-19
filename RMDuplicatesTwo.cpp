/**************************************
Author: Nishchal Agrawal
Problem URL: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

General Solution:
Iterate through array:
    if element is equal to previous two elements:
        delete element
        if next element is not equal to previous two elements:
            skip next two elements

Submission Metrics (6/18/2020) :
Time: 8ms (88.06 percentile of cpp submissions)
Memory: 11MB (62.35 percentile)
**************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 2; i < nums.size(); i++) {
            
            if (nums[i] == nums[i-1] && nums[i] == nums[i-2]) {
                
                nums.erase(nums.begin() + i);
                
                if (nums[i] != nums[i-1]) i++;
                else i--;
            }
        }
        return nums.size();
    }
};