// GFG Problem: Reverse a Stack
// Link: https://www.geeksforgeeks.org/problems/reverse-a-stack/1
// Difficulty: Easy
// Tags: Stack, Recursion, Backtracking

// ✅ Approach:
// To reverse a stack using recursion, we use two functions:
//
// 1️⃣ reverseStack(st)
//    - Recursively pops all elements from the stack.
//    - When recursion returns, inserts each popped element at the *bottom*.
//
// 2️⃣ insertAtEnd(st, element)
//    - Pops elements until the stack becomes empty.
//    - Inserts the target element at the bottom.
//    - Pushes back the popped elements (backtracking).
//
// This approach reverses the stack *without using any extra data structure*
// except the recursion call stack.
//
// ⏳ Time Complexity:
// O(N²) — because each element insertion at bottom takes O(N)
//
// 📦 Space Complexity:
// O(N) recursion stack

class Solution {
public:

    // Inserts an element at the bottom of the stack
    void insertAtEnd(stack<int> &st, int element) {

        // Base Case: If stack is empty, simply push element
        if(st.empty()){
            st.push(element);
            return;
        }

        // Pop the top and hold it temporarily
        int top = st.top();
        st.pop();

        // Recursively reach the bottom
        insertAtEnd(st, element);

        // Backtrack: push the saved element back
        st.push(top);
    }

    // Reverses the entire stack using recursion
    void reverseStack(stack<int> &st) {

        // Base Case: empty stack
        if(st.empty()){
            return;
        }

        // Remove the top element
        int top = st.top();
        st.pop();

        // Recursively reverse the remaining stack
        reverseStack(st);

        // Insert the removed element at the bottom
        insertAtEnd(st, top);
    }
};
