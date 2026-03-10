// Leetcode Problem: 926. Flip String to Monotone Increasing
// Link: https://leetcode.com/problems/flip-string-to-monotone-increasing/
// Difficulty: Medium
// Tags: Dynamic Programming, String

// ✅ Problem Idea:
// We are given a binary string. We need to make it **monotone increasing**.
// That means the string should look like:
// 000...111
// (all 0s first, then all 1s)
//
// We can flip any character (0 → 1 or 1 → 0).
// The goal is to **minimize the number of flips**.

// ✅ Approach:
// Use **Recursion + Memoization (DP)**.
//
// At each index we decide:
// 1️⃣ Flip the current character
// 2️⃣ Do not flip the current character
//
// We also track `prev_val` which represents the value of the previous character
// in the constructed monotone string.
//
// prev_val can be:
// 0 → we are still allowed to place 0 or 1
// 1 → we can only place 1 (cannot place 0 anymore)
//
// We compute the minimum flips for both choices
// and store results in DP table to avoid recomputation.

class Solution {
public:
    int n;

    // Recursive function
    // curr_index → current position in string
    // prev_val   → value of previously placed character
    // t          → memoization table
    int solve(string &s, int curr_index, int prev_val, vector<vector<int>>& t) {

        // Base Case:
        // If we reach end of string, no more flips needed
        if(curr_index >= n)
            return 0;

        // Return already computed result
        if(t[curr_index][prev_val] != -1)
            return t[curr_index][prev_val];

        int flip    = INT_MAX;
        int no_flip = INT_MAX;

        // Case when current character is '0'
        if(s[curr_index] == '0') {

            // If previous value is 1
            // placing 0 would break monotonic property
            if(prev_val == 1) {
                // We must flip 0 → 1
                flip = 1 + solve(s, curr_index+1, 1, t);
            }
            else {
                // Option 1: Flip 0 → 1
                flip = 1 + solve(s, curr_index+1, 1, t);

                // Option 2: Keep 0
                no_flip = solve(s, curr_index+1, 0, t);
            }
        }

        // Case when current character is '1'
        else if(s[curr_index] == '1')
        {
            // If previous value is 1
            // we can keep it as 1
            if(prev_val == 1) {
                no_flip = solve(s, curr_index+1, 1, t);
            }
            else {
                // Option 1: Flip 1 → 0
                flip = 1 + solve(s, curr_index+1, 0, t);

                // Option 2: Keep 1
                no_flip = solve(s, curr_index+1, 1, t);
            }
        }

        // Store and return minimum flips
        return t[curr_index][prev_val] = min(flip, no_flip);
    }

    int minFlipsMonoIncr(string s) {

        n = s.length();

        // DP table:
        // t[index][prev_val]
        vector<vector<int>> t(n+1, vector<int>(2, -1));

        // Start recursion from index 0 with previous value = 0
        return solve(s, 0, 0, t);
    }
};