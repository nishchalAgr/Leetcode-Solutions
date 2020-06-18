/**************************************
Author: Nishchal Agrawal
Problem URL: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3364/

General Solution:
Iterate through array:
    C = current element
    N = number of elements not visited + 1
    if C >= N 
        if max < N
            max = N

Submission Metrics (6/18/2020) :
Time: 36ms (85.35 percentile of cpp submissions)
Memory: 19MB (5.36 percentile)
**************************************/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int size = citations.size();
        int max = 0;
        
        for (int i = 0; i < size; i++) {
            
            if (citations[i] >= size-i && max < size-i) max = size-i;
        }
        
        return max;
    }
};