// Leetcode Problem: 279. Perfect Squares
// Link: https://leetcode.com/problems/perfect-squares/
// Difficulty: Medium
// Tags: Dynamic Programming, Recursion, Math

// ✅ Approach:
// This problem asks us to find the minimum number of perfect square numbers
// (like 1, 4, 9, 16, ...) whose sum equals n.
//
// We use **Recursion + Memoization (Top Down Dynamic Programming)**.
//
// Idea:
// For a given number `n`, try subtracting all possible perfect squares
// (1², 2², 3² ... ≤ n).
//
// For each square:
//     n = n - (i*i)
//
// Then recursively compute the minimum squares needed for the remaining value.
//
// To avoid recomputation, we store already computed results in a DP array.
//
// dp[n] = minimum number of perfect squares needed to form n.

class Solution {
public:

    int dp[10001];  // Memoization array to store results for numbers

    // Recursive function to compute minimum number of perfect squares
    int solve(int n){

        // Base Case:
        // If n becomes 0, no numbers are needed
        if(n == 0)
            return 0;

        // If already computed, return stored result
        if(dp[n] != -1)
            return dp[n];

        int min_count = INT_MAX;  // Store minimum squares required

        // Try all perfect squares less than or equal to n
        for(int i = 1; i * i <= n; i++){

            // Choose square (i*i) and solve for remaining value
            int result = 1 + solve(n - (i * i));

            // Update minimum
            min_count = min(min_count, result);
        }

        // Store result in DP table
        return dp[n] = min_count;
    }

    int numSquares(int n) {

        // Initialize DP array with -1 (not computed)
        memset(dp, -1, sizeof(dp));

        // Start recursion
        return solve(n);
        
    }
};