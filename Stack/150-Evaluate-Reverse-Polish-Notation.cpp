// Leetcode Problem: 150. Evaluate Reverse Polish Notation
// Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Difficulty: Medium
// Tags: Stack, Array, Math

// ✅ Approach:
// Use a stack to evaluate the expression.
// Traverse each token in the input list:
//
// 1. If the token is a number → push it onto the stack
// 2. If the token is an operator (+, -, *, /):
//    - Pop the top two elements from the stack
//    - Apply the operator (order matters: a operator b)
//    - Push the result back onto the stack
//
// After processing all tokens, the stack will contain
// only one element, which is the final result.

class Solution {
public:

    // Helper function to perform arithmetic operation
    int operation(int a, int b, string token) {

        // Perform operation based on the operator
        if(token == "+") {
            return a + b;
        } 
        else if(token == "-") {
            return a - b;
        } 
        else if(token == "*") {
            // Cast to long to avoid overflow during multiplication
            return long(a) * long(b);
        } 
        else {  // token == "/"
            // Division truncates toward zero as per problem statement
            return a / b;
        }
    }

    int evalRPN(vector<string>& tokens) {

        stack<int> stk;  // Stack to store operands

        // Traverse each token
        for(auto& token : tokens) {

            // If token is an operator
            if(token == "+" || token == "-" || token == "*" || token == "/") {

                // Pop two operands (note: order is important)
                int b = stk.top();
                stk.pop();

                int a = stk.top();
                stk.pop();

                // Apply the operation
                int res = operation(a, b, token);

                // Push the result back onto the stack
                stk.push(res);

            } 
            else {
                // Token is a number, convert and push to stack
                stk.push(stoi(token));
            }
        }

        // Final result will be at the top of the stack
        return stk.top();
    }
};
