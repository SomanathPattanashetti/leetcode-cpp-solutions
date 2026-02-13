// Leetcode Problem: 3163. String Compression III
// Link: https://leetcode.com/problems/string-compression-iii/
// Difficulty: Easy
// Tags: String, Two Pointers

// ✅ Approach:
// We compress the string by counting consecutive repeating characters.
// But there is one condition:
//   ➝ We can store at most 9 consecutive characters at a time.
//
// Steps:
// 1. Traverse the string using index `i`.
// 2. For each character, count how many times it repeats consecutively.
// 3. Stop counting if:
//      - Character changes OR
//      - Count reaches 9 (limit condition)
// 4. Append (count + character) to the result string.
// 5. Continue until the entire string is processed.
//
// Example:
// Input  : "aaaaaaaaaaaa" (12 times 'a')
// Output : "9a3a"
// Because maximum allowed count is 9 at once.

class Solution {
public:
    string compressedString(string word) {
        
        string comp = "";   // Stores final compressed string
        int n = word.length();
        int i = 0;          // Pointer to traverse string
        
        while(i < n) {
            
            int count = 0;      // Count occurrences of current character
            char ch = word[i];  // Current character
            
            // Count consecutive same characters
            // Stop if:
            //  - End of string
            //  - Count reaches 9
            //  - Character changes
            while(i < n && count < 9 && word[i] == ch) {
                count++;
                i++;
            }
            
            // Append count and character to result
            comp += to_string(count) + ch;
        }
        
        return comp;   // Return compressed string
    }
};
