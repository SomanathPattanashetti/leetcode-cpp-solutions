// Leetcode Problem: 713. Subarray Product Less Than K
// Link: https://leetcode.com/problems/subarray-product-less-than-k/
// Difficulty: Medium
// Tags: Array, Sliding Window, Two Pointers

// ✅ Approach:
// Use the Sliding Window (Two Pointers) technique.
// We maintain a window [i, j] such that the product of all elements
// in the window is always less than k.
//
// Steps:
// 1. Expand the window by moving pointer j and multiply nums[j] to product.
// 2. If product becomes >= k, shrink the window from the left (i++)
//    until product < k.
// 3. For each valid window ending at j, the number of valid subarrays
//    is (j - i + 1).
//
// Edge Case:
// If k <= 1, no valid subarray exists because all elements are positive.

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        // If k is 0 or 1, no subarray can have product < k
        if (k <= 1) {
            return 0;
        }

        int n = nums.size();

        int i = 0, j = 0;     // Sliding window pointers
        int count = 0;       // Stores total valid subarrays
        int product = 1;     // Product of current window

        // Expand the window using pointer j
        while (j < n) {

            // Multiply current element to product
            product *= nums[j];

            // Shrink the window until product < k
            while (product >= k) {
                product /= nums[i];
                i++;
            }

            // Number of valid subarrays ending at index j
            count += (j - i + 1);

            // Move right pointer
            j++;
        }

        return count;
    }
};
