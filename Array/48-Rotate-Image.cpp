// Leetcode Problem: 48. Rotate Image
// Link: https://leetcode.com/problems/rotate-image/
// Difficulty: Medium
// Tags: Array, Matrix, Math

// ✅ Approach:
// Rotate the matrix 90 degrees clockwise **in-place**.
//
// The rotation is done in 2 simple steps:
// 1️⃣ Transpose the matrix (convert rows into columns)
// 2️⃣ Reverse each row
//
// This avoids using extra space and works efficiently.

// Example:
// Original:
// 1 2 3
// 4 5 6
// 7 8 9
//
// After Transpose:
// 1 4 7
// 2 5 8
// 3 6 9
//
// After Reversing Rows:
// 7 4 1
// 8 5 2
// 9 6 3

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // 🔹 Step 1: Transpose the matrix
        // Swap elements across the main diagonal
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 🔹 Step 2: Reverse each row
        // This completes the 90-degree clockwise rotation
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
