// Leetcode Problem: 1456. Maximum Number of Vowels in a Substring of Given Length
// Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
// Difficulty: Medium
// Tags: String, Sliding Window, Two Pointers

// ✅ Approach:
// Use the Sliding Window technique with two pointers (i and j).
// Maintain a window of size k and count the number of vowels in the current window.
//
// Steps:
// 1. Expand the window by moving pointer j.
// 2. If the current character is a vowel, increment count.
// 3. When window size becomes k:
//    - Update the maximum vowel count.
//    - Remove the left character (i) from the window if it is a vowel.
//    - Slide the window forward by incrementing i.
// 4. Continue until the end of the string.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxVowels(string s, int k) {

        int n = s.length();
        int i = 0, j = 0;          // Two pointers for sliding window
        int count = 0;            // Current vowel count in window
        int max_count = 0;        // Maximum vowels found

        // Lambda function to check if a character is a vowel
        auto isVowel = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };

        // Traverse the string using the right pointer
        while (j < n) {

            // If current character is a vowel, increment count
            if (isVowel(s[j])) {
                count++;
            }

            // When window size becomes exactly k
            if (j - i + 1 == k) {

                // Update maximum vowel count
                max_count = max(max_count, count);

                // Before sliding window, remove left character's effect
                if (isVowel(s[i])) {
                    count--;
                }

                // Move left pointer forward
                i++;
            }

            // Move right pointer forward
            j++;
        }

        return max_count;
    }
};
