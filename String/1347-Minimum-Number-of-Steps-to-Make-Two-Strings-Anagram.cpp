// Leetcode Problem: 1347. Minimum Number of Steps to Make Two Strings Anagram
// Link: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
// Difficulty: Medium
// Tags: String, Hash Table, Counting

// ✅ Approach:
// Use a frequency array of size 26 to track character differences.
// Increment count for characters in string `s`.
// Decrement count for characters in string `t`.
//
// After processing both strings:
// - Positive values in the frequency array indicate extra characters in `s`
// - These extra characters need to be replaced to make `t` an anagram
//
// Sum only the positive values to get the minimum steps required.

class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();

        // Frequency array for characters 'a' to 'z'
        int mp[26] = {0};

        // Count characters from both strings
        for(int i = 0; i < n; i++) {
            mp[s[i] - 'a']++;  // Increment for s
            mp[t[i] - 'a']--;  // Decrement for t
        }

        int result = 0;

        // Count only extra characters from s
        for(int i = 0; i < 26; i++) {
            // Only positive values indicate required replacements
            result += max(0, mp[i]);
        }

        return result;  // Minimum number of steps
    }
};
