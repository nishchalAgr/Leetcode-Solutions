-------------------------------
Author: Nishchal Agrawal
Problem URL: https://leetcode.com/problems/find-all-duplicates-in-an-array

My Approach:
Iterate through the array:
	At index i:
		if nums[nums[i] - 1] is positive:
			make it negative
		if nums[nums[i] - 1] is negative:
			add abs(nums[i]) to duplicate array
return duplicate array

Time Complexity: O(size of input array)
Memory: O(number of duplicates) = O(n/2) //comment: the only space is used to store duplicates to be returned
-------------------------------

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            
            int index;
            int num = nums[i];

            if (num < 0) index = -num - 1;
            else index = num - 1;
            
            if (nums[index] < 0) {
                if (num < 0) ans.push_back(-num);
                else ans.push_back(num);
            }
            else nums[index] *= -1;
        }
        return ans;
    }
};
