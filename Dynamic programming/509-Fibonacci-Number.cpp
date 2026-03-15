// Leetcode Problem: 509. Fibonacci Number
// Link: https://leetcode.com/problems/fibonacci-number/
// Difficulty: Easy
// Tags: Dynamic Programming, Recursion, Memoization

// ✅ Approach:
// We use Recursion with Memoization (Top-Down Dynamic Programming).
//
// The Fibonacci sequence follows the relation:
// F(n) = F(n-1) + F(n-2)
//
// Base cases:
// F(0) = 0
// F(1) = 1
//
// Instead of recalculating values multiple times (as in plain recursion),
// we store already computed results in a DP array.
// If a value is already computed, we directly return it.

class Solution {
public:
    
    vector<int> dp;   // DP array to store computed Fibonacci values

    // Recursive function to compute Fibonacci
    int solve(int n){

        // 🔹 Base Case:
        // If n is 0 or 1, return n directly
        if(n <= 1)
            return n;

        // 🔹 If already computed, return stored result
        if(dp[n] != -1)
            return dp[n];

        // 🔹 Compute Fibonacci using recurrence relation
        return dp[n] = solve(n-1) + solve(n-2);
    }

    int fib(int n) {

        // Initialize DP array with -1
        // Size 31 is enough because constraints allow n ≤ 30
        dp.resize(31, -1);

        // Start recursion
        return solve(n);
        
    }
};