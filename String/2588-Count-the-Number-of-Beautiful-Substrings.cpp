// Leetcode Problem: 2588. Count the Number of Beautiful Substrings
// Link: https://leetcode.com/problems/count-the-number-of-beautiful-substrings/
// Difficulty: Medium
// Tags: String, Brute Force, Math

// ✅ Definition of Beautiful Substring:
// A substring is considered "beautiful" if:
// 1. Number of vowels == number of consonants
// 2. (vowels × consonants) is divisible by k

// ✅ Approach:
// - Use a brute-force approach to check all substrings.
// - Fix a starting index `i` and extend the substring till `j`.
// - Maintain counts of vowels and consonants.
// - For every substring, check the two beautiful conditions.
// - If both conditions satisfy, increment the result counter.
//
// Note:
// Total substrings = O(n²), which is acceptable for given constraints.

class Solution {
public:
    int beautifulSubstrings(string s, int k) {

        // Set to quickly check whether a character is a vowel
        unordered_set<char> isVowel{'A','E','I','O','U','a','e','i','o','u'};

        int n = s.length();
        int res = 0;  // Stores count of beautiful substrings

        // Outer loop: starting index of substring
        for(int i = 0; i < n; i++) {

            int vowel = 0;
            int cons = 0;

            // Inner loop: ending index of substring
            for(int j = i; j < n; j++) {

                // Check if current character is vowel or consonant
                if(isVowel.count(s[j]))
                    vowel++;
                else
                    cons++;

                // Check beautiful substring conditions
                if(vowel == cons && (vowel * cons) % k == 0)
                    res++;
            }
        }

        return res;  // Final count
    }
};
