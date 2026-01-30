// Leetcode Problem: 1544. Make The String Great
// Link: https://leetcode.com/problems/make-the-string-great/
// Difficulty: Easy
// Tags: String, Stack

// ✅ Approach:
// We process the string character by character and build a result string.
// The idea is similar to using a stack.
//
// Two adjacent characters are considered "bad" if:
//  - They are the same letter
//  - One is uppercase and the other is lowercase
//  - ASCII difference between them is 32
//
// If such a pair is found, we remove the previous character.
// Otherwise, we add the current character to the result.

class Solution {
public:
    string makeGood(string s) {

        string res = "";  // Acts like a stack to store valid characters

        // Traverse each character in the input string
        for (auto &ch : s) {

            // Check if result is not empty AND
            // last character and current character form a bad pair
            // (difference of 32 in ASCII)
            if (res.size() > 0 &&
                (res.back() == ch - 32 || res.back() == ch + 32)) {

                // ❌ Bad pair found → remove last character
                res.pop_back();
            }
            else {
                // ✅ No conflict → add character to result
                res.push_back(ch);
            }
        }

        // Final string after removing all bad adjacent pairs
        return res;
    }
};
