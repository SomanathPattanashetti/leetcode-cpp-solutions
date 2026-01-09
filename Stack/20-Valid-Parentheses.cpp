// Leetcode Problem: 20. Valid Parentheses
// Link: https://leetcode.com/problems/valid-parentheses/
// Difficulty: Easy
// Tags: Stack, String

// ✅ Approach:
// Use a stack to keep track of expected closing brackets.
// 
// Rules followed:
// 1. When we see an opening bracket '(', '{', '[', we push its
//    corresponding closing bracket ')', '}', ']' onto the stack.
// 2. When we see a closing bracket:
//    - If the stack is empty → invalid string
//    - If the top of the stack does not match the current bracket → invalid
//    - Otherwise, pop the stack (matched pair found)
// 3. At the end, if the stack is empty → valid parentheses string

class Solution {
public:
    bool isValid(string s) {

        stack<char> stk;  // Stack to store expected closing brackets

        // Traverse each character in the string
        for(auto& ch : s) {

            // 🔹 If opening bracket, push corresponding closing bracket
            if(ch == '(')
                stk.push(')');

            else if(ch == '{')
                stk.push('}');

            else if(ch == '[')
                stk.push(']');

            // 🔹 If closing bracket
            // Condition 1: stack is empty (no matching opening)
            // Condition 2: top of stack does not match current closing bracket
            else if(stk.empty() || stk.top() != ch)
                return false;

            // 🔹 Valid match found, pop from stack
            else
                stk.pop();
        }

        // 🔹 If stack is empty, all brackets matched correctly
        return stk.empty();
    }   
};
