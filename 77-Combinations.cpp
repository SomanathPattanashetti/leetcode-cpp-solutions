// Leetcode Problem: 77. Combinations
// Link: https://leetcode.com/problems/combinations/
// Difficulty: Medium
// Tags: Backtracking

// ✅ Approach:
// Use Backtracking to generate all combinations of size 'k' from numbers 1 to n.
// We build combinations in increasing order to avoid duplicates.
// At each step, we choose a number 'i' starting from 'start', include it,
// and recursively build the rest of the combination.
//
// When k becomes 0 → we have selected k numbers → store the current combination (temp).
//
// After exploring a number, we backtrack by removing it and trying the next number.

class Solution {
public:
    vector<vector<int>> res;  // Stores all combinations

    // Recursive function to generate combinations
    void solve(int n, int k, int start, vector<int>& temp) {

        // Base Case:
        // If k == 0, we have selected a complete combination
        if (k == 0) {
            res.push_back(temp);  // Store the formed combination
            return;
        }

        // Try all numbers from 'start' to 'n'
        for (int i = start; i <= n; i++) {

            // 🔹 Choose 'i' and include it in the current combination
            temp.push_back(i);

            // Recurse to pick remaining (k - 1) numbers, next start is i+1
            solve(n, k - 1, i + 1, temp);

            // 🔙 Backtrack: remove the last added number
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        vector<int> temp;  // Temporary list to build one combination

        solve(n, k, 1, temp);  // Start with number 1

        return res;  // Contains all combinations of size k
    }
};
