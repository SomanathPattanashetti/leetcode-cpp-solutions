// Leetcode Problem: 22. Generate Parentheses
// Link: https://leetcode.com/problems/generate-parentheses/
// Difficulty: Medium
// Tags: String, Backtracking

// ✅ Approach:
// We use **Backtracking** to generate all valid combinations of parentheses.
// At any time, we can add:
//   1. '(' → only if we still have remaining '(' to place (open < n)
//   2. ')' → only if it does NOT make the sequence invalid
//            i.e., ')' can be added only if close < open
//
// The idea:
// - Build the string step-by-step
// - Ensure that the string is always valid (never let ')' count exceed '(' count)
// - When the string reaches length = 2*n, it is a valid combination
//
// This guarantees we NEVER generate invalid strings → efficient and clean backtracking.

class Solution {
public:

    vector<string> res;  // Stores all valid parentheses combinations

    // Recursive backtracking function
    void solve(int n, int open, int close, string& temp) {

        // Base Case:
        // If length is 2*n, it means we placed n '(' and n ')'
        if(temp.length() == 2 * n){
            res.push_back(temp);
            return;
        }

        // 🔹 Choice 1: Add '(' if we still have '(' available
        if(open < n){
            temp.push_back('(');
            solve(n, open + 1, close, temp);
            temp.pop_back(); // Backtrack
        }

        // 🔹 Choice 2: Add ')' only if it does not make the sequence invalid
        // We cannot close more than we have opened
        if(close < open){
            temp.push_back(')');
            solve(n, open, close + 1, temp);
            temp.pop_back(); // Backtrack
        }
    }

    vector<string> generateParenthesis(int n) {

        int open = 0;      // Number of '(' placed
        int close = 0;     // Number of ')' placed
        string temp = "";  // Current string being built

        solve(n, open, close, temp);

        return res;        // All valid parentheses combinations
    }
};
