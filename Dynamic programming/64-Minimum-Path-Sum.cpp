// Leetcode Problem: 64. Minimum Path Sum
// Link: https://leetcode.com/problems/minimum-path-sum/
// Difficulty: Medium
// Tags: Array, Dynamic Programming, Matrix

// ✅ Approach:
// Use Top-Down Dynamic Programming (Memoization).
// Start from cell (0, 0) and recursively find the minimum path sum to reach (m-1, n-1).
// From each cell, we can only move in 2 directions:
//  1. Right
//  2. Down
//
// At every cell, choose the minimum path sum between moving right and moving down.
// Store already computed results in dp to avoid repeated calculations.

class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    // Recursive function to find minimum path sum from cell (i, j) to destination
    int solve(vector<vector<int>>& grid, int i, int j) {

        // Base Case:
        // If we reached the bottom-right cell, return its value
        if(i == m - 1 && j == n - 1)
            return grid[i][j];

        // If already computed, return stored answer
        if(dp[i][j] != -1)
            return dp[i][j];

        // If we are in the last row, we can only move right
        if(i == m - 1)
            return dp[i][j] = grid[i][j] + solve(grid, i, j + 1);

        // If we are in the last column, we can only move down
        else if(j == n - 1)
            return dp[i][j] = grid[i][j] + solve(grid, i + 1, j);

        else {
            // Move right
            int right = solve(grid, i, j + 1);

            // Move down
            int down = solve(grid, i + 1, j);

            // Store minimum of both paths
            return dp[i][j] = grid[i][j] + min(right, down);
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Initialize dp with -1 for memoization
        dp.resize(201, vector<int>(201, -1));

        // Start from top-left cell
        return solve(grid, 0, 0);
    }
};