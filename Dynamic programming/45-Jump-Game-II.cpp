// Leetcode Problem: 45. Jump Game II
// Link: https://leetcode.com/problems/jump-game-ii/
// Difficulty: Medium
// Tags: Array, Dynamic Programming, Greedy

// ✅ Approach:
// We use Recursion + Memoization (Top-Down DP) to find the minimum number of jumps.
//
// From each index, we can jump from 1 to nums[idx] positions ahead.
// We recursively try all possible jumps and choose the minimum jumps needed to reach the end.
//
// To avoid recomputing the same states, we store results in a DP array.
// dp[i] stores the minimum jumps required to reach the end from index i.
//
// If the index reaches or crosses the last position, no more jumps are needed.

class Solution {
public:

    // Recursive function to calculate minimum jumps from index 'idx'
    int solve(vector<int>& nums, int idx, vector<int>& dp){

        // Base Case:
        // If we reach or cross the last index, no jumps are needed
        if(idx >= nums.size()-1)
            return 0;

        // If already computed, return stored result
        if(dp[idx] != -1)
            return dp[idx];

        // Initialize answer with large value
        int ans = INT_MAX;

        // Try all possible jumps from current position
        for(int i = 1; i <= nums[idx]; i++){

            // Recursively calculate jumps from next position
            int jumps = solve(nums, idx + i, dp);

            // If reachable, update minimum jumps
            if(jumps != INT_MAX)
                ans = min(ans, jumps + 1);
        }

        // Store result in DP and return
        return dp[idx] = ans;
    }

    int jump(vector<int>& nums) {

        int n = nums.size();

        // DP array to store minimum jumps from each index
        vector<int> dp(n, -1);

        // Start solving from index 0
        return solve(nums, 0, dp);
    }
};