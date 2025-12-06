// Leetcode Problem: 90. Subsets II
// Link: https://leetcode.com/problems/subsets-ii/
// Difficulty: Medium
// Tags: Array, Backtracking, Sorting

// ✅ Approach:
// We must generate all subsets, but avoid duplicates because the array may contain repeating elements.
//
// 🔹 Key Idea:
// Sort the array so duplicate elements are adjacent.  
// While making subsets, after exploring the "include" branch for nums[idx],  
// we skip all consecutive duplicates in the "exclude" branch.
//
// At every index, we have 2 choices:
//   1. Include nums[idx] in the subset.
//   2. Exclude nums[idx], but while excluding, skip all duplicate values to avoid repeated subsets.
//
// Whenever idx reaches n, we store the current subset.

class Solution {
public:
    vector<vector<int>> res;   // Stores all unique subsets

    // Recursive function to generate subsets with duplicates handled
    void solve(vector<int>& nums, int idx, vector<int>& temp, int n) {

        // Base Case:
        // If index crosses array size, store the subset
        if(idx >= n){
            res.push_back(temp);
            return;
        }

        // 🔹 Choice 1: Include nums[idx]
        temp.push_back(nums[idx]);
        solve(nums, idx + 1, temp, n);
        temp.pop_back();  // Backtrack

        // 🔹 Choice 2: Exclude nums[idx]
        // Skip all duplicates to avoid creating duplicate subsets
        int i = idx + 1;
        while(i < n && nums[i] == nums[i - 1]) {
            i++;
        }

        // Explore the exclude path starting from first non-duplicate
        solve(nums, i, temp, n);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());  // Sorting helps in skipping duplicates

        vector<int> temp;  // Current subset
        int n = nums.size();

        solve(nums, 0, temp, n);

        return res;  // Contains all unique subsets
    }
};
