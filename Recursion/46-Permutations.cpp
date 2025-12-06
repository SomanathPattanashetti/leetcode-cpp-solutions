// Leetcode Problem: 46. Permutations
// Link: https://leetcode.com/problems/permutations/
// Difficulty: Medium
// Tags: Array, Backtracking

// ✅ Approach:
// Use Backtracking with Swapping.
// For each position 'idx', try placing every element nums[i] (i >= idx).
// Steps:
//  1. Swap nums[i] with nums[idx]  → choose nums[i] for this position
//  2. Recurse for the next position (idx + 1)
//  3. Swap back → undo the choice (backtracking)
//
// When idx reaches n, the current array is a full permutation → store it.

class Solution {
public:
    vector<vector<int>> res;  // Stores all permutations

    // Recursive function to generate permutations
    void solve(vector<int>& nums, int idx, int n) {

        // Base Case:
        // All positions fixed → store the current permutation
        if(idx >= n) {
            res.push_back(nums);
            return;
        }

        // Try placing every element at position 'idx'
        for(int i = idx; i < n; i++) {

            // 🔹 Step 1: Swap to choose nums[i] for this position
            swap(nums[i], nums[idx]);

            // 🔹 Step 2: Recurse for next index
            solve(nums, idx + 1, n);

            // 🔹 Step 3: Swap back to restore original order (backtracking)
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        solve(nums, 0, n);  // Start from index 0

        return res;         // Contains all permutations
    }
};
