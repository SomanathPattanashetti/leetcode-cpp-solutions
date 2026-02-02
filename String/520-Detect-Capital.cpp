// Leetcode Problem: 520. Detect Capital
// Link: https://leetcode.com/problems/detect-capital/
// Difficulty: Easy
// Tags: String

// ✅ Approach:
// A word uses capital letters correctly if:
//  1. All letters are lowercase (e.g., "leetcode")
//  2. All letters are uppercase (e.g., "USA")
//  3. Only the first letter is uppercase (e.g., "Google")
//
// We count how many uppercase letters are present
// and validate the word based on the above rules.

class Solution {
public:
    bool detectCapitalUse(string word) {

        int n = word.length();   // Length of the word
        int C_count = 0;         // Count of uppercase letters

        // Count uppercase characters in the word
        for (auto& ch : word) {
            if (isupper(ch))
                C_count++;
        }

        // ✅ Valid cases:
        // 1. No uppercase letters → all lowercase
        // 2. Uppercase count equals word length → all uppercase
        // 3. Exactly one uppercase letter and it is the first character
        if ((C_count == 0) || 
            (C_count == n) || 
            (C_count == 1 && isupper(word[0])))
            return true;

        // ❌ Any other combination is invalid
        return false;
    }
};
