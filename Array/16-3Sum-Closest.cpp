// Leetcode Problem: 16. 3Sum Closest
// Link: https://leetcode.com/problems/3sum-closest/
// Difficulty: Medium
// Tags: Array, Two Pointers, Sorting

// ✅ Approach:
// Sort the array first.
// Fix one element (nums[k]) and use two pointers (i, j) to find
// the best possible sum close to the target.
//
// For every fixed k:
//  - i starts from k+1 (next element)
//  - j starts from the end of the array
//
// Calculate the sum of nums[k] + nums[i] + nums[j].
// Update closest_sum if this sum is closer to the target.
// Move pointers based on comparison with target:
//  - If sum < target → move left pointer forward (i++)
//  - If sum > target → move right pointer backward (j--)
// This ensures O(n²) time complexity.

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n(nums.size());

        // Stores the closest sum found so far
        int closest_sum = 1000000;

        // Sort the array to apply two-pointer technique
        sort(begin(nums), end(nums));

        // Fix the first element one by one
        for(int k = 0; k <= n - 3; k++) {

            int i = k + 1;      // Left pointer
            int j = n - 1;      // Right pointer

            // Two-pointer search for remaining two elements
            while(i < j) {

                int sum = nums[k] + nums[i] + nums[j];

                // Update closest sum if current sum is closer to target
                if(abs(target - sum) < abs(target - closest_sum))
                    closest_sum = sum;

                // Move pointers based on sum comparison
                if(sum < target)
                    i++;        // Need a larger sum
                else
                    j--;        // Need a smaller sum
            }
        }

        // Return the sum closest to target
        return closest_sum;
    }
};
