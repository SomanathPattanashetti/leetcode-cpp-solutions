// Leetcode Problem: 316. Remove Duplicate Letters
// Link: https://leetcode.com/problems/remove-duplicate-letters/
// Difficulty: Medium
// Tags: String, Stack, Greedy

// ✅ Problem Statement:
// Given a string s, remove duplicate letters so that every letter appears once
// and the resulting string is the smallest in lexicographical order.

// ✅ Approach (Greedy + Stack-like behavior):
// 1. Store the last index of every character in the string.
// 2. Use a boolean array `taken` to check if a character is already included.
// 3. Build the result string character by character.
// 4. While adding a new character:
//    - Remove previously added characters if:
//        a) They are lexicographically larger than current character
//        b) They appear again later in the string
// 5. This ensures:
//    - Each character appears once
//    - Result is lexicographically smallest

class Solution {
public:
    string removeDuplicateLetters(string s) {

        int n = s.length();

        // Tracks whether a character is already in result
        vector<bool> taken(26, false);

        // Stores last occurrence index of each character
        vector<int> lastIndex(26);

        // Step 1: Fill last occurrence of each character
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            lastIndex[ch - 'a'] = i;
        }

        string res;

        // Step 2: Iterate through the string
        for(int i = 0; i < n; i++) {

            char curr_ch = s[i];
            int curr_idx = curr_ch - 'a';

            // If character already included, skip
            if(taken[curr_idx])
                continue;

            // Step 3: Maintain lexicographical order
            // Remove characters from result if:
            // 1. They are greater than current character
            // 2. They appear again later in the string
            while(!res.empty() &&
                  res.back() > curr_ch &&
                  lastIndex[res.back() - 'a'] > i) {

                taken[res.back() - 'a'] = false;
                res.pop_back();
            }

            // Add current character to result
            res.push_back(curr_ch);
            taken[curr_idx] = true;
        }

        return res;
    }
};