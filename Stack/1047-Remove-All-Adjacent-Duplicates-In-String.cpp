// Leetcode Problem: 1047. Remove All Adjacent Duplicates In String
// Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Difficulty: Easy
// Tags: String, Stack

// ✅ Approach:
// Use a stack to remove adjacent duplicate characters.
// Traverse the string character by character.
//
// Rules:
// - If the stack is empty OR the top of the stack is not equal to current character,
//   push the character into the stack.
// - If the top of the stack is equal to the current character,
//   pop the stack (this removes the adjacent duplicate pair).
//
// This simulates removing duplicates in one pass efficiently.

class Solution {
public:
    string removeDuplicates(string s) {

        stack<char> stk;   // Stack to keep track of characters

        // Traverse each character in the string
        for(auto& ch : s){

            // If stack is empty OR current character is different
            if(stk.empty() || stk.top() != ch){
                stk.push(ch);   // Push character into stack
            }
            else{
                stk.pop();      // Remove adjacent duplicate
            }
        }

        string res;

        // Stack contains characters in reverse order
        // Pop all elements to form result string
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }

        // Reverse to restore correct order
        reverse(begin(res), end(res));

        return res;
    }
};
