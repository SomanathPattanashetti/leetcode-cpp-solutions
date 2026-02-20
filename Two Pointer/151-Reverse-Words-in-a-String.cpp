// Leetcode Problem: 151. Reverse Words in a String
// Link: https://leetcode.com/problems/reverse-words-in-a-string/
// Difficulty: Medium
// Tags: String, Two Pointers, In-place Manipulation

// ✅ Approach:
// We solve this in 3 main steps (in-place, O(1) extra space)
//
// 1) Reverse the entire string
//    "the sky is blue" → "eulb si yks eht"
//
// 2) Traverse the string and extract each word
//    While copying characters forward, we automatically remove extra spaces.
//
// 3) Reverse each word individually to restore correct word order
//    "eulb si yks eht" → "blue is sky the"
//
// Important:
// - l = start index of current word
// - r = position where next valid character should be written
// - i = iterator scanning original string
//
// This also removes:
//   • leading spaces
//   • trailing spaces
//   • multiple spaces between words

class Solution {
public:
    string reverseWords(string s) {

        int n = s.length();

        // Step 1: Reverse entire string
        reverse(begin(s), end(s));

        int l = 0, r = 0, i = 0;

        // Step 2: Traverse and copy words one by one
        while(i < n){

            // Copy characters of a word
            while(i < n && s[i] != ' '){
                s[r++] = s[i++];
            }

            // If we copied a valid word
            if(l < r){

                // Step 3: Reverse the word to correct order
                reverse(begin(s)+l, begin(s)+r);

                // Add single space after word
                s[r] = ' ';
                r++;

                // Move l to start of next word
                l = r;
            }

            // Skip spaces
            i++;
        }

        // Remove last extra space
        return s.substr(0, r-1);
    }
};