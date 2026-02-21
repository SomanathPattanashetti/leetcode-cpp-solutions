// Leetcode Problem: 1750. Minimum Length of String After Deleting Similar Ends
// Link: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
// Difficulty: Medium
// Tags: Two Pointers, String

// ✅ Approach:
// We use the Two Pointer technique.
//
// Idea:
// We are allowed to delete SAME characters from both ends of the string.
// So if the first and last character are equal,
// we keep removing that character from left and right.
//
// Steps:
// 1. Start two pointers:
//      i -> beginning of string
//      j -> end of string
//
// 2. If s[i] == s[j]:
//      Remove ALL consecutive same characters from left
//      Remove ALL consecutive same characters from right
//
// 3. Repeat until:
//      - characters at ends are different
//      - OR pointers cross
//
// 4. Remaining length = j - i + 1

class Solution {
public:
    int minimumLength(string s) {

        int n = s.length();

        // Two pointers
        int i = 0;
        int j = n - 1;

        // Continue only if characters at both ends match
        while(i < j && s[i] == s[j]) {

            // Character to remove from both sides
            char ch = s[i];

            // Remove same characters from left side
            while(i < j && s[i] == ch) {
                i++;
            }

            // Remove same characters from right side
            while(j >= i && s[j] == ch) {
                j--;
            }
        }

        // Remaining string length
        return j - i + 1;
    }
};