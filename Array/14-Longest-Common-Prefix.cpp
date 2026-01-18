// Leetcode Problem: 14. Longest Common Prefix
// Link: https://leetcode.com/problems/longest-common-prefix/
// Difficulty: Easy
// Tags: String, Array

// ✅ Approach:
// The idea is to compare characters column-wise across all strings.
//
// Steps:
// 1. Find the length of the smallest string (min_len)
//    → The common prefix cannot be longer than this.
// 2. Start comparing characters from index 0 up to min_len.
// 3. For each index `i`, compare strs[0][i] with the same index
//    character of all other strings.
// 4. If any mismatch is found, return the substring from index 0 to i.
// 5. If all characters match till min_len, return that full prefix.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // Step 1: Find the minimum length among all strings
        int min_len = INT_MAX;
        for(auto& str : strs) {
            min_len = min(min_len, (int)str.length());
        }

        int i = 0;

        // Step 2: Compare characters index by index
        while(i < min_len) {

            // Step 3: Compare current character with all strings
            for(auto& str : strs) {

                // Mismatch found → return prefix till previous index
                if(str[i] != strs[0][i])
                    return strs[0].substr(0, i);
            }

            // Move to next character
            i++;
        }

        // Step 4: All characters matched till min_len
        return strs[0].substr(0, i);
    }
};
