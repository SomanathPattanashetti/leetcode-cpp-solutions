// Leetcode Problem: 1493. Longest Subarray of 1's After Deleting One Element
// Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
// Difficulty: Medium
// Tags: Array, Sliding Window, Two Pointers

// ✅ Approach:
// We use a Sliding Window technique with two pointers (i and j).
// The idea is to maintain a window that contains at most ONE zero.
// Since one element must be deleted, the window length is calculated as (j - i).
//
// Key observations:
// - When we encounter the first zero, we record its index.
// - When we encounter another zero, we shift the left pointer (i)
//   to the position right after the previous zero.
// - This ensures the window always has at most one zero.
// - The maximum length of such a window gives the answer.

class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n = nums.size();

        int i = 0, j = 0;              // Sliding window pointers
        int last_zero_idx = -1;        // Stores index of last seen zero
        int res = 0;                   // Stores maximum result

        while (j < n) {

            // If current element is zero
            if (nums[j] == 0) {
                // Move left pointer to right of previous zero
                i = last_zero_idx + 1;
                // Update last zero position
                last_zero_idx = j;
            }

            // Since one element must be deleted, window length = j - i
            res = max(res, j - i);

            j++;  // Expand window
        }

        return res;
    }
};
