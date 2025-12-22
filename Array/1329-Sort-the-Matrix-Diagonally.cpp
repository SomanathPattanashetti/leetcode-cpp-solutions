// Leetcode Problem: 1329. Sort the Matrix Diagonally
// Link: https://leetcode.com/problems/sort-the-matrix-diagonally/
// Difficulty: Medium
// Tags: Array, Matrix, Hash Map, Sorting

// ✅ Approach:
// Elements lying on the same diagonal have the same (i - j) value.
// 1️⃣ Traverse the matrix and group elements by their diagonal key (i - j)
//    using an unordered_map.
// 2️⃣ Sort each diagonal independently.
// 3️⃣ Traverse the matrix again from bottom-right to top-left and
//    place the largest remaining element of each diagonal back into the matrix.
//    (Using back() ensures correct ascending order along the diagonal.)

class Solution {
public:
    typedef vector<int> V;   // Alias for cleaner code

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        unordered_map<int, V> mp;  // Maps diagonal key (i - j) to its elements

        int m = mat.size();        // Number of rows
        int n = mat[0].size();     // Number of columns

        // 🔹 Step 1: Store elements of each diagonal
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mp[i - j].push_back(mat[i][j]);
            }
        }

        // 🔹 Step 2: Sort each diagonal
        for(auto& it : mp){
            sort(it.second.begin(), it.second.end());
        }

        // 🔹 Step 3: Fill the matrix back (from bottom-right)
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                mat[i][j] = mp[i - j].back();  // Get largest remaining element
                mp[i - j].pop_back();          // Remove used element
            }
        }

        return mat;  // Final diagonally sorted matrix
    }
};
