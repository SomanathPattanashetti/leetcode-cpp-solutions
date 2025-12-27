// LeetCode Problem: 2090. K Radius Subarray Averages
// Link: https://leetcode.com/problems/k-radius-subarray-averages/
// Difficulty: Medium
// Tags: Array, Prefix Sum, Sliding Window

// ✅ Approach:
// We need to calculate the average of a subarray of radius `k` for each index i.
// That means we need elements from index (i - k) to (i + k).
// Total elements in each window = (2 * k + 1).
//
// To efficiently calculate subarray sums, we use the Prefix Sum technique.
//
// Steps:
// 1. If k == 0, every element is its own average → return nums directly.
// 2. If array size is smaller than (2*k + 1), no valid averages exist → return array filled with -1.
// 3. Build a prefix sum array to store cumulative sums.
// 4. For each valid center index i, calculate subarray sum using prefix sum.
// 5. Divide the sum by (2*k + 1) and store it in result.

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {

        // Special case: radius 0 → each element itself is the average
        if (k == 0) return nums;

        int n = nums.size();

        // Initialize result array with -1 (default for invalid indices)
        vector<int> res(n, -1);

        // If window size exceeds array length, no valid averages possible
        if (2 * k + 1 > n) return res;

        // Prefix sum array to store cumulative sums
        vector<long long> prefix_sum(n);
        prefix_sum[0] = nums[0];

        // Build prefix sum
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }

        // Iterate over valid center indices
        for (int i = k; i < n - k; i++) {

            int left_idx  = i - k;   // Left boundary of window
            int right_idx = i + k;   // Right boundary of window

            // Calculate subarray sum using prefix sum
            long long sum = prefix_sum[right_idx];

            if (left_idx > 0) {
                sum -= prefix_sum[left_idx - 1];
            }

            // Store average
            res[i] = sum / (2 * k + 1);
        }

        return res;
    }
};
