// Leetcode Problem: 557. Reverse Words in a String III
// Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Difficulty: Easy
// Tags: String, Two Pointers

// ✅ Approach:
// We traverse the string character by character.
// Whenever we find the start of a word (non-space character):
//  1. Mark the starting index of the word.
//  2. Move forward until we reach a space or end of string.
//  3. Reverse only that word using two pointers / STL reverse.
//  
// This way, each word is reversed in-place without changing
// the order of words or spaces in the string.

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();  // Length of the string

        // Traverse the entire string
        for (int i = 0; i < n; i++) {

            // If current character is not a space, it marks
            // the beginning of a word
            if (s[i] != ' ') {

                int j = i;  // Pointer to find the end of the word

                // Move j until we hit a space or reach end of string
                while (j < n && s[j] != ' ') {
                    j++;
                }

                // Reverse the characters of the current word
                reverse(s.begin() + i, s.begin() + j);

                // Move i to the end of the current word
                i = j;
            }
        }

        // Return the modified string with reversed words
        return s;
    }
};