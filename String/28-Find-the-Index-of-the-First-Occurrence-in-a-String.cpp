// LeetCode Problem: 28. Find the Index of the First Occurrence in a String
// Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// Difficulty: Easy
// Tags: String, Two Pointers

// ✅ Approach:
// We use a simple Brute Force string matching technique.
//
// Idea:
// - Try every index 'i' in s1 as a starting position.
// - From that index, compare characters of s2 one by one.
// - If all characters of s2 match consecutively, return the starting index.
// - If mismatch happens, break and move to the next starting index.
//
// Time Complexity: O(m * n)
//   where m = length of s1 (haystack)
//         n = length of s2 (needle)
//
// Space Complexity: O(1)

class Solution {
public:
    int strStr(string s1, string s2) {

        int m = s1.length();   // Length of main string (haystack)
        int n = s2.length();   // Length of pattern string (needle)

        // Traverse each possible starting index in s1
        for(int i = 0; i < m; i++) {

            // Compare substring starting at index i
            for(int j = 0; j < n; j++) {

                // If characters don't match, stop checking this index
                if(s1[i + j] != s2[j])
                    break;

                // If we reached last character of s2 and all matched
                if(j == n - 1)
                    return i;   // Return starting index
            }
        }

        // If no match found, return -1
        return -1;
    }
};
