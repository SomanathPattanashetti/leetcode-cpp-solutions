// Leetcode Problem: 213. House Robber II
// Link: https://leetcode.com/problems/house-robber-ii/
// Difficulty: Medium
// Tags: Dynamic Programming, Recursion, Memoization

// ✅ Approach:
// This is an extension of House Robber I, but houses are arranged in a circle.
// Because the first and last houses are adjacent, we cannot rob both.
//
// So we break the problem into two linear cases:
// 1️⃣ Rob houses from index 0 to n-2 (exclude last house)
// 2️⃣ Rob houses from index 1 to n-1 (exclude first house)
//
// We solve both cases using recursion + memoization
// and take the maximum of the two results.

class Solution {
public:
    int dp[101];  // DP array to store maximum money from index i onward

    // Recursive function to compute max money from idx to n
    int solve(vector<int>& nums, int idx, int n) {

        // Base Case:
        // If index goes beyond the allowed range
        if(idx > n)
            return 0;

        // If already computed, return stored result
        if(dp[idx] != -1)
            return dp[idx];

        // 🔹 Choice 1: Rob current house and skip next house
        int steal = nums[idx] + solve(nums, idx + 2, n);

        // 🔹 Choice 2: Skip current house
        int skip = solve(nums, idx + 1, n);

        // Store and return the maximum of both choices
        return dp[idx] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        // Edge Cases:
        if(n == 1)
            return nums[0];

        if(n == 2)
            return max(nums[0], nums[1]);

        // Case 1️⃣: Consider houses from index 0 to n-2
        memset(dp, -1, sizeof(dp));
        int take_zero_th_index_house = solve(nums, 0, n - 2);

        // Case 2️⃣: Consider houses from index 1 to n-1
        memset(dp, -1, sizeof(dp));
        int take_first_index_house = solve(nums, 1, n - 1);

        // Return the maximum of both cases
        return max(take_zero_th_index_house, take_first_index_house);
    }
};
