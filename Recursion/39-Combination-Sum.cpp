// Leetcode Problem: 39. Combination Sum
// Link: https://leetcode.com/problems/combination-sum/
// Difficulty: Medium
// Tags: Array, Backtracking

// ✅ Approach:
// We use Backtracking to explore all possible combinations whose sum equals the target.
// At each index, we have 3 choices:
//   1. Include nums[idx] and move to next index (use element once)
//   2. Include nums[idx] and stay on same index (allow using same element multiple times)
//   3. Exclude nums[idx] and move ahead
//
// We also use a set to avoid duplicate combinations.
// `temp` stores the current combination being built.
// When target becomes 0 → valid combination → store it.

class Solution {
public:

    vector<vector<int>> res;   // Stores all unique valid combinations
    set<vector<int>> st;       // To avoid duplicates

    // Recursive Backtracking Function
    void solve(vector<int>& nums, int idx, vector<int>& temp, int target) {

        // Base Case 1: If target goes negative → this path is invalid
        if (idx >= nums.size() || target < 0)
            return;

        // Base Case 2: If target becomes 0 → valid combination found
        if (target == 0) {
            if (st.find(temp) == st.end()) {
                res.push_back(temp);   // Store combination
                st.insert(temp);       // Mark as used to avoid duplicates
            }
            return;
        }

        // 🔹 Choice 1: Pick nums[idx] and move to next index
        temp.push_back(nums[idx]);
        solve(nums, idx + 1, temp, target - nums[idx]);

        // 🔹 Choice 2: Pick nums[idx] again (allow repetition)
        solve(nums, idx, temp, target - nums[idx]);

        // Backtrack: Remove last added element
        temp.pop_back();

        // 🔹 Choice 3: Skip nums[idx] and move ahead
        solve(nums, idx + 1, temp, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;         // Current combination

        solve(nums, 0, temp, target);

        return res;               // All valid unique combinations
    }
};
