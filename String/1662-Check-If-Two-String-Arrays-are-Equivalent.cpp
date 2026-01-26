// Leetcode Problem: 1662. Check If Two String Arrays are Equivalent
// Link: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
// Difficulty: Easy
// Tags: Array, String, Two Pointers

// ✅ Approach:
// Instead of concatenating strings (which uses extra space),
// we compare characters one by one using TWO POINTERS.
//
// We maintain:
// - w1i → index for word1 array
// - w2i → index for word2 array
// - i   → character index inside word1[w1i]
// - j   → character index inside word2[w2i]
//
// We move character by character across both arrays.
// If at any point characters mismatch → return false.
// At the end, both arrays must be fully traversed.

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

        int i = 0, j = 0;          // Character pointers for current strings
        int m = word1.size();     // Number of strings in word1
        int n = word2.size();     // Number of strings in word2

        int w1i = 0, w2i = 0;     // Word-level pointers

        // Traverse both string arrays simultaneously
        while (w1i < m && w2i < n) {

            // Compare current characters
            if (word1[w1i][i] != word2[w2i][j])
                return false;

            // Move to next character
            i++;
            j++;

            // If end of current word in word1 is reached
            if (i == word1[w1i].length()) {
                i = 0;
                w1i++;
            }

            // If end of current word in word2 is reached
            if (j == word2[w2i].length()) {
                j = 0;
                w2i++;
            }
        }

        // Both arrays must be completely traversed
        if (w1i == m && w2i == n)
            return true;

        return false;
    }
};