// Leetcode Problem: 15. 3Sum
// Link: https://leetcode.com/problems/3sum/
// Difficulty: Medium
// Tags: Array, Two Pointers, Sorting

// ✅ Approach:
// 1. Sort the array to handle duplicates easily and use two pointers.
// 2. Fix one element nums[k] and find two numbers such that:
//      nums[k] + nums[i] + nums[j] == 0
// 3. Use two pointers (i and j) to search efficiently.
// 4. Skip duplicate elements to avoid repeated triplets.
//
// Time Complexity: O(n^2)
// Space Complexity: O(1) (ignoring result storage)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // Sort the array
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> res;  // Stores all unique triplets

        // Fix the first element one by one
        for(int k = 0; k < n - 2; k++) {

            // Skip duplicate values for the first element
            if(k > 0 && nums[k] == nums[k - 1])
                continue;

            int i = k + 1;     // Left pointer
            int j = n - 1;     // Right pointer

            // Two-pointer approach
            while(i < j) {
                int sum = nums[k] + nums[i] + nums[j];

                // If sum is too large, decrease it
                if(sum > 0) {
                    j--;
                }
                // If sum is too small, increase it
                else if(sum < 0) {
                    i++;
                }
                // Found a valid triplet
                else {
                    res.push_back({nums[k], nums[i], nums[j]});

                    // Skip duplicate values for second element
                    while(i < j && nums[i] == nums[i + 1])
                        i++;

                    // Skip duplicate values for third element
                    while(i < j && nums[j] == nums[j - 1])
                        j--;

                    // Move both pointers after storing result
                    i++;
                    j--;
                }
            }
        }

        return res;  // All unique triplets with sum = 0
    }
};
