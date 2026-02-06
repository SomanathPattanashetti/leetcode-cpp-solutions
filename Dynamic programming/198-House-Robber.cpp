// LeetCode Problem: 198. House Robber
// Link: https://leetcode.com/problems/house-robber/
// Difficulty: Medium
// Tags: Dynamic Programming, Recursion, Memoization

// ✅ Approach:
// Use Recursion + Memoization (Top-Down DP).
//
// At each house (index), we have 2 choices:
//  1. Steal from the current house → move to idx + 2
//  2. Skip the current house → move to idx + 1
//
// We compute the maximum money possible from each index
// and store it in dp[] to avoid recomputation.

class Solution {
public:
    int dp[101];   // dp[i] stores max money that can be robbed starting from index i
    int n;         // total number of houses

    // Recursive function to calculate maximum robbery amount
    int solve(vector<int>& nums, int idx) {

        // 🛑 Base Case:
        // If index goes beyond the last house, no money can be robbed
        if (idx >= n)
            return 0;

        // 🔁 If already computed, return stored result
        if (dp[idx] != -1)
            return dp[idx];

        // 🔹 Choice 1: Steal from current house
        // Move to idx + 2 because adjacent houses cannot be robbed
        int steal = nums[idx] + solve(nums, idx + 2);

        // 🔹 Choice 2: Skip current house
        // Move to next house
        int skip = solve(nums, idx + 1);

        // 🧠 Store and return the maximum of both choices
        return dp[idx] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        n = nums.size();

        // Initialize dp array with -1 (uncomputed state)
        memset(dp, -1, sizeof(dp));

        // Start solving from index 0
        return solve(nums, 0);
    }
};
