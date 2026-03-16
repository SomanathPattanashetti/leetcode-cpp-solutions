// Leetcode Problem: 300. Longest Increasing Subsequence
// Link: https://leetcode.com/problems/longest-increasing-subsequence/
// Difficulty: Medium
// Tags: Dynamic Programming, Recursion, Memoization

// ✅ Approach:
// We use Recursion + Memoization (Top Down DP).
//
// At every index we have two choices:
//  1. Take the current element if it forms an increasing sequence
//  2. Skip the current element
//
// prev_idx → index of the previously selected element
// curr_idx → current index we are exploring
//
// If nums[curr_idx] > nums[prev_idx], we can include it in LIS.
// Otherwise we skip it.
//
// We store results in DP table t[prev_idx][curr_idx] to avoid recomputation.

class Solution {
public:
    int n;

    // DP table for memoization
    int t[2501][2501];

    // Recursive function to calculate LIS
    int lis(vector<int>& nums, int prev_idx, int curr_idx) {

        // Base Case:
        // If we reach the end of array, no more elements can be added
        if(curr_idx == n)
            return 0;

        // If result already computed, return it
        if(prev_idx != -1 && t[prev_idx][curr_idx] != -1)
            return t[prev_idx][curr_idx];

        int taken = 0;

        // 🔹 Choice 1: Take the current element
        // Allowed if no previous element OR current element is greater
        if(prev_idx == -1 || nums[curr_idx] > nums[prev_idx])
            taken = 1 + lis(nums, curr_idx, curr_idx + 1);

        // 🔹 Choice 2: Skip the current element
        int not_taken = lis(nums, prev_idx, curr_idx + 1);

        // Store result in DP table (only if prev_idx is valid)
        if(prev_idx != -1)
            t[prev_idx][curr_idx] = max(taken, not_taken);

        // Return the best choice
        return max(taken, not_taken);
    }

    int lengthOfLIS(vector<int>& nums) {

        // Initialize DP table with -1
        memset(t, -1, sizeof(t));

        n = nums.size();

        // Start recursion with no previous element
        return lis(nums, -1, 0);
    }
};