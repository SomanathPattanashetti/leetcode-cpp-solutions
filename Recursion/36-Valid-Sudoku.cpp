// Leetcode Problem: 36. Valid Sudoku
// Link: https://leetcode.com/problems/valid-sudoku/
// Difficulty: Medium
// Tags: Hashing, Matrix, Validation

// ✅ Approach (Using HashSet + Box Indexing):
// We traverse the 9x9 Sudoku board in ONE single loop and validate:
//  1. Each row
//  2. Each column
//  3. Each 3×3 box
//
// For every filled cell board[i][j], we create three unique strings:
//
//   "digit_row_i"   → checks duplicate in the same row
//   "digit_col_j"   → checks duplicate in the same column
//   "digit_box_r_c" → checks duplicate inside its 3×3 box
//
// Box Index Formula:
//   box_row = i / 3
//   box_col = j / 3
//
// Example: i=5, j=7 → box_row = 1, box_col = 2  (middle-right box)
//
// If ANY of the three keys already exists in the hashset → Sudoku is invalid.
// Otherwise, insert all three keys into the hashset and continue.
//
// Since each cell is processed only once, the time complexity is O(81) ≈ O(1).

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                // Skip empty cells
                if(board[i][j] == '.') continue;

                // Create unique identifiers
                string row = string(1, board[i][j]) + "_row_" + to_string(i);
                string col = string(1, board[i][j]) + "_col_" + to_string(j);
                string box = string(1, board[i][j]) + "_box_" + to_string(i/3) + "_" + to_string(j/3);

                // If any one already exists → invalid
                if(st.count(row) || st.count(col) || st.count(box))
                    return false;

                // Insert all three
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }

        return true; // All checks passed
    }
};
