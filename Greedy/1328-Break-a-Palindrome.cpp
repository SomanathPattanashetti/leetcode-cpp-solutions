// Leetcode Problem: 1328. Break a Palindrome
// Link: https://leetcode.com/problems/break-a-palindrome/
// Difficulty: Medium
// Tags: String, Greedy

// ✅ Approach:
// Since the string is already a palindrome, we need to make it
// the lexicographically smallest NON-palindrome by changing only one character.
//
// 🔹 Key Idea:
// - To make the string smallest, try replacing the first non-'a' character
//   in the first half with 'a'.
// - We only check the first half because changing the second half
//   would give a larger string unnecessarily.
// - If all characters in the first half are already 'a',
//   then change the last character to 'b'.
//
// 🔹 Special Case:
// - If the string length is 1, it's impossible to make it non-palindrome,
//   so return an empty string.

class Solution {
public:
    string breakPalindrome(string palindrome) {

        int n = palindrome.length();  // Length of the palindrome

        // Base Case:
        // A single character string cannot be converted into a non-palindrome
        if(n == 1)
            return "";

        // Traverse only the first half of the string
        for(int i = 0; i < n / 2; i++) {

            // If current character is not 'a',
            // replace it with 'a' to get the smallest lexicographical string
            if(palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        // If all characters in the first half are 'a',
        // change the last character to 'b'
        palindrome[n - 1] = 'b';

        return palindrome;
    }
};