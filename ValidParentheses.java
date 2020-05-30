/*
---------------------------------------------------------------------------------------------
Written By: Nishchal Agrawal

Problem URL: https://leetcode.com/problems/valid-parentheses/

General Approach:
    Keep a stack that contains the open brackets
    Iterate across the string:
        if current char is a closed bracket:
            if the stack is empty or if the top element in the stack is not the matching open bracket, return false
            else, pop the stack
        else, push current char to the stack
    if the stack is empty, return true
    else, return false

Leetcode Submission Metrics (May 29, 2020):
    Runtime: 1ms (98.71% percentile)
    Memory: 37.5MB (5.06% percentile)
---------------------------------------------------------------------------------------------
*/

import java.util.*; 

class Solution {
    public boolean isValid(String s) {
        
        Stack<Character> stack = new Stack<Character>();
        
        for (int i = 0; i < s.length(); i++) {
            
            char current = s.charAt(i);
            
            if (current == ']') {
                
                if (stack.empty()) return false;
                
                current = stack.pop();
                
                if (current != '[') return false;
                
                continue;
            }
            
            if (current == '}') {
                
                if (stack.empty()) return false;
                
                current = stack.pop();
                
                if (current != '{') return false;
                
                continue;
            }
            
            if (current == ')') {
                
                if (stack.empty()) return false;
                
                current = stack.pop();
                
                if (current != '(') return false;
                
                continue;
            }
            
            stack.push(current);
        }
        
        return stack.empty();
    }
}