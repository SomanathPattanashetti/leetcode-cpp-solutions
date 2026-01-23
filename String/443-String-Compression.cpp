// Leetcode Problem: 443. String Compression
// Link: https://leetcode.com/problems/string-compression/
// Difficulty: Medium
// Tags: Two Pointers, String, In-place

// ✅ Approach:
// Use Two Pointers technique to compress the string in-place.
//
// Pointer `i` → used to read characters from the input array
// Pointer `idx` → used to write the compressed result
//
// For each group of consecutive repeating characters:
// 1. Count how many times the current character repeats
// 2. Write the character once
// 3. If count > 1, write the digits of the count
//
// This ensures:
// - In-place modification
// - O(n) time complexity
// - O(1) extra space (excluding count string)

class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();

        int i = 0;      // Read pointer
        int idx = 0;    // Write pointer

        // Traverse the entire character array
        while (i < n) {

            char curr_ch = chars[i]; // Current character
            int count = 0;           // Count of current character

            // Count consecutive occurrences of curr_ch
            while (i < n && chars[i] == curr_ch) {
                count++;
                i++;
            }

            // Write the character once
            chars[idx] = curr_ch;
            idx++;

            // If character repeats, write the count
            if (count > 1) {
                string count_str = to_string(count);

                // Write each digit of the count
                for (char ch : count_str) {
                    chars[idx] = ch;
                    idx++;
                }
            }
        }

        // idx represents the new length of the compressed array
        return idx;
    }
};
