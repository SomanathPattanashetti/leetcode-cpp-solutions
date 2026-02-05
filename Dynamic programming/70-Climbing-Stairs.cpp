// Leetcode Problem: 70. Climbing Stairs
// Link: https://leetcode.com/problems/climbing-stairs/
// Difficulty: Easy
// Tags: Dynamic Programming, Recursion, Memoization

// ✅ Approach:
// This problem follows the Fibonacci pattern.
// To reach step `n`, we can come from:
//   1. Step (n - 1)
//   2. Step (n - 2)
//
// So, number of ways to reach step `n` = ways(n-1) + ways(n-2)
//
// We use recursion with memoization (Top-Down DP)
// to avoid recalculating overlapping subproblems.

class Solution {
public:
    int t[46];   // DP array to store computed results (constraints allow up to n = 45)

    // Recursive function to compute number of ways
    int solve(int n) {

        // 🛑 Base Cases:
        // If there are 0, 1, or 2 steps,
        // the number of ways equals n itself
        if(n == 0 || n == 1 || n == 2)
            return n;

        // 🔁 If result already computed, return it
        if(t[n] != -1)
            return t[n];

        // 🔹 Recursive calls
        int oneStep = solve(n - 1);
        int twoStep = solve(n - 2);

        // 🧠 Store and return the result
        return t[n] = oneStep + twoStep;
    }

    int climbStairs(int n) {

        // Initialize DP array with -1 (uncomputed state)
        memset(t, -1, sizeof(t));

        // Start solving from step `n`
        return solve(n);
    }
};
