// Leetcode Problem: 645. Set Mismatch
// Link: https://leetcode.com/problems/set-mismatch/
// Difficulty: Easy
// Tags: Array, Hashing, Math

// ✅ Approach:
// We use the **index marking technique** to detect the duplicate and missing numbers.
// Given an array of size n containing numbers from 1 to n:
//  - One number is duplicated
//  - One number is missing
//
// Key Idea:
// Each number x should ideally appear at index (x - 1).
// We mark visited numbers by making nums[x - 1] negative.
//
// Steps:
// 1. Traverse the array:
//    - For each number, take its absolute value (num).
//    - Map it to index = num - 1.
//    - If nums[index] is already negative → num is the duplicate.
//    - Otherwise, mark nums[index] as visited by multiplying by -1.
//
// 2. Traverse again to find the missing number:
//    - The index which remains positive was never visited.
//    - Missing number = index + 1.
//
// Time Complexity: O(n)
// Space Complexity: O(1) (in-place modification)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int n = nums.size();
        int duplicate = -1;  // Stores the duplicate number
        int missing = -1;    // Stores the missing number

        // 🔹 First pass: Identify the duplicate number
        for(int i = 0; i < n; i++) {

            int num = abs(nums[i]);   // Get original value
            int idx = num - 1;        // Corresponding index

            // If already visited, this number is duplicate
            if(nums[idx] < 0) {
                duplicate = num;
            } 
            // Mark as visited
            else {
                nums[idx] *= -1;
            }
        }

        // 🔹 Second pass: Identify the missing number
        for(int i = 0; i < n; i++) {

            // Positive value means index was never visited
            if(nums[i] > 0) {
                missing = i + 1;
                break;
            }
        }

        // Return [duplicate, missing]
        return {duplicate, missing};
    }
};
