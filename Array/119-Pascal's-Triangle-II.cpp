// Leetcode Problem: 119. Pascal's Triangle II
// Link: https://leetcode.com/problems/pascals-triangle-ii/
// Difficulty: Easy
// Tags: Array, Dynamic Programming

// ✅ Approach:
// We build Pascal’s Triangle row by row starting from row 0.
// Instead of storing the entire triangle, we only keep the previous row.
//
// Key Idea:
// - Each row starts and ends with 1.
// - Each middle element is the sum of two elements directly above it:
//      curr[j] = prev[j] + prev[j-1]
//
// We repeat this process until we reach the required rowIndex.
// Finally, we return the last computed row.

class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int> prev;   // Stores the previous row of Pascal's Triangle

        // Loop to build rows from 0 to rowIndex
        for(int i = 0; i < rowIndex + 1; i++) {

            // Create current row with all elements initialized to 1
            vector<int> curr(i + 1, 1);

            // Fill the middle elements using the previous row
            for(int j = 1; j < i; j++) {
                curr[j] = prev[j] + prev[j - 1];
            }

            // Update prev to the current row for next iteration
            prev = curr;
        }

        // prev now contains the required row
        return prev;
    }
};
