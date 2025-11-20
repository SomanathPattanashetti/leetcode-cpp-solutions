// Leetcode Problem: 78. Subsets
// Link: https://leetcode.com/problems/subsets/
// Difficulty: Medium
// Tags: Array, Backtracking, Bit Manipulation

// ✅ Approach:
// Use Backtracking to generate all subsets.
// At each index, we have 2 choices:
//  1. Include the current element in the subset
//  2. Exclude the current element
//
// We recursively explore both choices.
// When we reach the end of the array, we store the current subset (temp) in result.

class Solution {
public:
    vector<vector<int>> result;  // Stores all subsets

    // Recursive function to generate subsets
    void solve(vector<int>& nums, int idx, vector<int>& temp) {

        // Base Case:
        // When index reaches the array size, store the current subset
        if(idx >= nums.size()) {
            result.push_back(temp);
            return;
        }

        // 🔹 Choice 1: Include nums[idx] in the subset
        temp.push_back(nums[idx]);
        solve(nums, idx + 1, temp);

        // Backtrack: remove the added element
        temp.pop_back();

        // 🔹 Choice 2: Exclude nums[idx] and move ahead
        solve(nums, idx + 1, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;  // Current subset

        solve(nums, 0, temp);  // Start from index 0

        return result;  // Contains all subsets
    }
};
