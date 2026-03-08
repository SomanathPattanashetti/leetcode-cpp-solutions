// Leetcode Problem: 55. Jump Game
// Link: https://leetcode.com/problems/jump-game/
// Difficulty: Medium
// Tags: Array, Dynamic Programming, Greedy

// ✅ Approach:
// Use Recursion + Memoization (Top-Down DP).
//
// From each index, we try all possible jumps from 1 to nums[idx].
// If any jump can reach the last index, then the answer is true.
//
// To avoid recomputation, we store results in a DP array.
// dp[idx] stores whether we can reach the end starting from idx.
//
// Base Case:
// If we reach the last index (n-1), return true.

class Solution {
public:

    int dp[10001];   // DP array to store already computed results

    // Recursive function to check if we can reach the end from index idx
    bool solve(vector<int>& nums, int idx, int n){

        // Base Case: If we reach the last index
        if(idx == n-1)
            return true;

        // If already computed, return stored result
        if(dp[idx] != -1)
            return dp[idx];

        // Try all possible jumps from current position
        for(int i = 1; i <= nums[idx]; i++){

            // Check if jumping i steps leads to a valid path
            if(solve(nums, idx + i, n))
                return dp[idx] = true;
        }

        // If none of the jumps work, mark as false
        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {

        // Initialize DP array with -1 (uncomputed state)
        memset(dp, -1, sizeof(dp));

        int n = nums.size();

        // Start checking from index 0
        return solve(nums, 0 , n);
    }
};