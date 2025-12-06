// Leetcode Problem: 40. Combination Sum II
// Link: https://leetcode.com/problems/combination-sum-ii/
// Difficulty: Medium
// Tags: Array, Backtracking

// ✅ Approach:
// Use Backtracking to find all unique combinations where the numbers sum to the target.
// BUT each number can be used **only once**, and the array may contain **duplicates**.
//
// 🔹 Key Idea 1: Sort the array first.
//      Sorting helps group duplicates together so we can skip repeated values and avoid duplicate combinations.
//
// 🔹 Key Idea 2: At each step, try picking nums[i], then recurse for remaining sum.
//      After choosing nums[i], the next recursive call starts from i+1 (because each element can be used once).
//
// 🔹 Key Idea 3: Skip duplicates:
//      If nums[i] == nums[i-1] and i > idx → skip this element to avoid repeating the same combination.
//
// 🔹 Base Cases:
//      ✔ If target becomes 0 → store the current combination
//      ✘ If index goes out of bounds or target < 0 → stop exploring this path

class Solution {
public:
    vector<vector<int>> all_combo;  // Stores all unique valid combinations

    // Recursive function to generate combinations
    void getALLCombinations(vector<int>& nums, int idx, int target,
                            vector<int>& temp, int n) {

        // 🎯 Base Case 1: Found a valid combination
        if(target == 0){
            all_combo.push_back(temp);
            return;
        }

        // ❌ Base Case 2: Out of bounds or sum exceeded
        if(idx >= n || target < 0)
            return;

        // Loop through choices starting from current index
        for(int i = idx; i < n; i++){

            // 🚫 Skip duplicates to avoid repeating same combination
            if(i > idx && nums[i] == nums[i - 1]){
                continue;
            }

            // 🔹 Choose nums[i]
            temp.push_back(nums[i]);

            // Recurse with updated sum and next index (i+1 because reuse not allowed)
            getALLCombinations(nums, i + 1, target - nums[i], temp, n);

            // 🔄 Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        // Step 1: Sort to handle duplicates
        sort(begin(nums), end(nums));

        vector<int> temp;
        int n = nums.size();

        // Step 2: Generate combinations
        getALLCombinations(nums, 0, target, temp, n);

        return all_combo;
    }
};
