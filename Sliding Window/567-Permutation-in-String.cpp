// Leetcode Problem: 567. Permutation in String
// Link: https://leetcode.com/problems/permutation-in-string/
// Difficulty: Medium
// Tags: Sliding Window, String, Hashing

// ✅ Approach:
// Use Sliding Window with Frequency Counting.
//
// Idea:
// A permutation of s1 will have the same character frequency.
// We maintain:
//  - freq1 → frequency of characters in s1
//  - freq2 → frequency of current window in s2
//
// Steps:
// 1. Count frequency of each character in s1.
// 2. Use a sliding window of size s1.length() on s2.
// 3. Expand window using pointer `j` and update freq2.
// 4. When window size equals s1 length:
//      - Compare freq1 and freq2
//      - If equal → permutation found
//      - Else, slide window by removing left character (`i`)
//
// Time Complexity: O(n2 * 26) ≈ O(n2)
// Space Complexity: O(26)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // Frequency arrays for s1 and sliding window in s2
        vector<int> freq1(26);
        vector<int> freq2(26);

        int n1 = s1.length();
        int n2 = s2.length();

        // Sliding window pointers
        int i = 0, j = 0;

        // Count frequency of characters in s1
        for(auto& ch : s1)
            freq1[ch - 'a']++;

        // Sliding window over s2
        while(j < n2) {

            // Add current character to window
            freq2[s2[j] - 'a']++;

            // When window size equals length of s1
            if(j - i + 1 == n1) {

                // Check if both frequency arrays match
                if(freq1 == freq2)
                    return true;

                // Remove the leftmost character from window
                freq2[s2[i] - 'a']--;
                i++;
            }

            // Expand window
            j++;
        }

        // No permutation found
        return false;
    }
};
