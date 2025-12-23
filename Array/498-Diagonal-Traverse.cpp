// Leetcode Problem: 498. Diagonal Traverse
// Link: https://leetcode.com/problems/diagonal-traverse/
// Difficulty: Medium
// Tags: Array, Matrix, Hash Map, Simulation

// ✅ Approach:
// The key observation is that all elements lying on the same diagonal
// have the same value of (row index + column index).
//
// Steps:
// 1. Traverse the matrix and group elements using (i + j) as the key.
//    - We store them in a map where:
//      key   = i + j  (diagonal index)
//      value = list of elements in that diagonal
//
// 2. Diagonals are processed in increasing order of (i + j),
//    which is naturally handled by `map`.
//
// 3. For alternate diagonals:
//    - Reverse the diagonal elements to match zig-zag order
//    - First diagonal is reversed, next is not, and so on
//
// 4. Append all diagonal elements to the result vector.

class Solution {
public:
    typedef vector<int> V;

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        // Map to store elements grouped by diagonal index (i + j)
        map<int, V> mp;

        int m = mat.size();        // Number of rows
        int n = mat[0].size();     // Number of columns

        // Step 1: Group elements by diagonal
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        bool flip = true;   // Controls reversing of diagonals
        V res;              // Final traversal order

        // Step 2: Process each diagonal
        for(auto& it : mp) {

            // Reverse elements for alternate diagonals
            if(flip) {
                reverse(it.second.begin(), it.second.end());
            }

            // Add diagonal elements to result
            for(auto& element : it.second) {
                res.push_back(element);
            }

            // Toggle direction for next diagonal
            flip = !flip;
        }

        return res;
    }
};
