// LeetCode Problem: 118. Pascal's Triangle
// Link: https://leetcode.com/problems/pascals-triangle/
// Difficulty: Easy
// Tags: Array, Dynamic Programming

// ✅ Approach:
// Build Pascal’s Triangle row by row using Dynamic Programming.
//
// Key Observations:
// 1. Each row starts and ends with 1.
// 2. Any middle element is the sum of two elements from the previous row:
//    res[i][j] = res[i-1][j-1] + res[i-1][j]
//
// Steps:
// - Create a 2D vector to store all rows.
// - Initialize each row with all 1s.
// - Fill the middle elements using values from the previous row.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        // Result vector to store Pascal's Triangle
        vector<vector<int>> res(numRows);

        // Iterate through each row
        for(int i = 0; i < numRows; i++) {

            // Initialize current row with (i + 1) elements, all set to 1
            res[i] = vector<int>(i + 1, 1);

            // Fill middle elements of the row
            for(int j = 1; j < i; j++) {

                // Each element is sum of two elements from the previous row
                res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
            }
        }

        // Return the completed Pascal's Triangle
        return res;
    }
};
