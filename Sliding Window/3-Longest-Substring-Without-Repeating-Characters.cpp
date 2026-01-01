// Leetcode Problem: 3. Longest Substring Without Repeating Characters
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Difficulty: Medium
// Tags: String, Sliding Window, Hash Set

// ✅ Approach:
// Use the Sliding Window technique with two pointers (i and j).
// Maintain a window [i..j] such that all characters inside the window are unique.
// Use an unordered_set to track characters currently present in the window.
//
// Steps:
// 1. Expand the window by moving pointer j.
// 2. If a duplicate character is found, shrink the window from the left (i)
//    until the duplicate is removed.
// 3. Update the maximum length after every valid window expansion.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();      // Length of the string
        int i = 0, j = 0;        // Sliding window pointers
        int max_len = 0;         // Stores maximum length found

        unordered_set<char> st;  // Stores unique characters in current window

        // Traverse the string using the right pointer
        while (j < n) {

            // If current character already exists in the set,
            // shrink the window from the left until it's removed
            while (st.find(s[j]) != st.end()) {
                st.erase(s[i]);  // Remove leftmost character
                i++;             // Move left pointer forward
            }

            // Insert current character into the set
            st.insert(s[j]);

            // Update maximum window length
            max_len = max(max_len, j - i + 1);

            // Move right pointer forward
            j++;
        }

        return max_len;  // Length of the longest valid substring
    }
};
