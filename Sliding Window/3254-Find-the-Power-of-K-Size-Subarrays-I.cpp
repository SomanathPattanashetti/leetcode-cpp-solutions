// Leetcode Problem: 3254. Find the Power of K-Size Subarrays I
// Link: https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/
// Difficulty: Medium
// Tags: Array, Sliding Window

// ✅ Approach:
// Use Sliding Window technique of size `k`.
// We track consecutive increasing elements (difference = 1).
//
// Idea:
// - Maintain two pointers `i` (window start) and `j` (window end).
// - Maintain `count` to track length of current consecutive increasing sequence.
// - If current element continues the sequence, increment `count`.
// - Otherwise, reset `count` to 1.
// - When window size becomes `k`:
//      • If `count >= k`, push the last element (nums[j]) as power
//      • Else, push -1
// - Slide the window forward.

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {

        // Special case:
        // If k == 1, every element itself is a valid subarray
        if(k == 1)
            return nums;

        int n(nums.size());

        int i(0), j(0);     // Sliding window pointers
        int count(1);      // Length of current consecutive increasing sequence
        vector<int> res;   // Stores the result for each window

        while(j < n){

            // Check if current element continues consecutive increasing order
            if(j > 0 && nums[j] == nums[j-1] + 1){
                count++;
            } else {
                // Reset count if sequence breaks
                count = 1;
            }

            // When window size reaches k
            if(j - i + 1 == k ){

                // If we have at least k consecutive numbers
                if(count >= k){
                    res.push_back(nums[j]);   // Last element is the power
                } else {
                    res.push_back(-1);        // Not a valid power
                }

                // Slide window from left
                i++;
            }

            // Expand window from right
            j++;
        }

        return res;
    }
};
