// Leetcode Problem: 62. Unique Paths
// Link: https://leetcode.com/problems/unique-paths/
// Difficulty: Medium
// Tags: Dynamic Programming, Recursion, Memoization, Grid

// ✅ Approach:
// We use Recursion + Memoization (Top-Down DP) to count the number of ways
// to reach the bottom-right corner of the grid.
//
// From any cell (i, j), we have only 2 possible moves:
//  1. Move Right  -> (i, j + 1)
//  2. Move Down   -> (i + 1, j)
//
// The total paths from a cell = paths from right + paths from down.
//
// To avoid recalculating the same states again and again,
// we store already computed results in a DP table (memoization).

class Solution {
public:

    vector<vector<int>> dp;   // DP table to store already computed results

    // Recursive function to count paths from cell (i, j)
    int solve(int i, int j, int m, int n){

        // ❌ If we go outside the grid, no valid path
        if(i >= m || j >= n)
            return 0;

        // ✅ If result already computed, return it (memoization)
        if(dp[i][j] != -1)
            return dp[i][j];

        // 🎯 If we reach last row or last column,
        // there is only ONE way to reach the destination
        if(i == m - 1 || j == n - 1)
            return 1;

        // Move Right
        int right = solve(i, j + 1, m, n);

        // Move Down
        int down = solve(i + 1, j, m, n);

        // Store and return total paths
        return dp[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {

        // Initialize DP table with -1 (meaning not computed yet)
        dp.resize(101, vector<int>(101, -1));

        // Start recursion from top-left cell (0,0)
        return solve(0, 0, m, n);
    }
};