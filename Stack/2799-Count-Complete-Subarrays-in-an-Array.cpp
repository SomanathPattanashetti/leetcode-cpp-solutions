// Leetcode Problem: 2799. Count Complete Subarrays in an Array
// Link: https://leetcode.com/problems/count-complete-subarrays-in-an-array/
// Difficulty: Medium
// Tags: Array, Hash Map, Sliding Window, Two Pointers

// ✅ Approach:
// A subarray is called *complete* if it contains **all distinct elements**
// present in the entire array.
//
// Steps:
// 1. First, find how many distinct elements exist in the whole array (k).
// 2. Use a Sliding Window (two pointers) with a frequency map.
// 3. Expand the right pointer (j) to include elements.
// 4. When the window contains all k distinct elements,
//    - Any extension of this window to the right will also be complete.
//    - So we add (n - j) to the answer.
// 5. Shrink the window from the left (i) and continue.

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

        // Store all distinct elements of the array
        unordered_set<int> st(begin(nums), end(nums));

        int n = nums.size();     // Length of array
        int k = st.size();       // Total number of distinct elements

        unordered_map<int, int> mp;  // Frequency map for current window

        int i = 0, j = 0;        // Sliding window pointers
        int res = 0;             // Result count

        // Expand the window using right pointer
        while (j < n) {

            // Include nums[j] into the window
            mp[nums[j]]++;

            // If window contains all k distinct elements
            while (mp.size() == k) {

                // All subarrays starting at i and ending from j to n-1 are complete
                res += n - j;

                // Remove nums[i] from the window
                mp[nums[i]]--;

                // If frequency becomes zero, erase it
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }

                // Move left pointer forward
                i++;
            }

            // Move right pointer forward
            j++;
        }

        return res;
    }
};
