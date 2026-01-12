// Leetcode Problem: 2461. Maximum Sum of Distinct Subarrays With Length K
// Link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
// Difficulty: Medium
// Tags: Sliding Window, Hash Set, Two Pointers

// ✅ Approach:
// We use the Sliding Window + Two Pointer technique.
// The idea is to maintain a window of size `k` that contains
// only distinct elements and track the maximum sum.
//
// Key points:
// - Use two pointers `i` (start) and `j` (end) for the window
// - Use an unordered_set to ensure all elements are distinct
// - Maintain a running sum of the current window
//
// Steps:
// 1. Expand the window using `j`
// 2. If a duplicate element appears, shrink the window from `i`
//    until the duplicate is removed
// 3. When window size becomes exactly `k`, update the maximum sum
// 4. Slide the window forward by removing the leftmost element

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();          // Size of the array

        int i = 0, j = 0;             // Two pointers for sliding window
        long long max_sum = 0;        // Stores maximum valid subarray sum
        long long sum = 0;            // Current window sum

        unordered_set<int> st;        // To store distinct elements in window

        while (j < n) {

            // 🔁 If nums[j] already exists in the set,
            // remove elements from the left until it becomes unique
            while (st.find(nums[j]) != st.end()) {
                sum -= nums[i];       // Remove left element from sum
                st.erase(nums[i]);    // Remove from set
                i++;                  // Move left pointer
            }

            // Add current element to window
            sum += nums[j];
            st.insert(nums[j]);

            // 🎯 If window size becomes exactly k
            if (j - i + 1 == k) {

                // Update maximum sum
                max_sum = max(max_sum, sum);

                // Slide window forward by removing left element
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            // Move right pointer
            j++;
        }

        return max_sum;   // Final answer
    }
};
