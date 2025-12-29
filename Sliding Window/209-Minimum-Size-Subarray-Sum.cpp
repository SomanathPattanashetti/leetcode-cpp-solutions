// Leetcode Problem: 209. Minimum Size Subarray Sum
// Link: https://leetcode.com/problems/minimum-size-subarray-sum/
// Difficulty: Medium
// Tags: Array, Sliding Window, Two Pointers

// ✅ Approach:
// Use the Sliding Window (Two Pointers) technique.
//
// Idea:
// Maintain a window [i .. j] such that:
//  - `j` expands the window by moving forward
//  - `i` shrinks the window when the sum becomes >= target
//
// Goal:
// Find the minimum length subarray whose sum is >= target.
//
// Steps:
// 1. Expand the window by adding nums[j] to sum
// 2. When sum >= target:
//      - Update minimum length
//      - Shrink window from the left to try for a smaller subarray
// 3. Continue until the end of the array

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        int min_len = INT_MAX;  // Stores minimum length found
        int sum = 0;            // Current window sum

        int i = 0, j = 0;       // Two pointers (sliding window)

        // Expand the window using j pointer
        while (j < n) {

            // Add current element to the window sum
            sum += nums[j];

            // Shrink the window from left while sum is valid
            while (sum >= target) {

                // Update minimum length
                min_len = min(min_len, j - i + 1);

                // Remove left element and move i forward
                sum -= nums[i];
                i++;
            }

            // Move right pointer forward
            j++;
        }

        // If no valid subarray found, return 0
        return min_len == INT_MAX ? 0 : min_len;
    }
};
