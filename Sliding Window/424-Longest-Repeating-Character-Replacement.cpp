// Leetcode Problem: 424. Longest Repeating Character Replacement
// Link: https://leetcode.com/problems/longest-repeating-character-replacement/
// Difficulty: Medium
// Tags: String, Sliding Window, Hash Map

// ✅ Approach:
// Use the Sliding Window technique to find the longest substring
// that can be converted into a string of repeating characters
// by replacing at most `k` characters.
//
// Key idea:
// - Maintain a window [i, j]
// - Track frequency of characters in the current window
// - Keep `max_freq` = frequency of the most common character in the window
//
// Condition:
// - If (window size - max_freq) > k → too many replacements needed
//   → shrink the window from the left
//
// Why it works:
// - We always try to expand the window
// - Shrinking happens only when replacements exceed k
// - `max_freq` does NOT need to be decreased while shrinking,
//   because it never affects correctness (optimization trick)

class Solution {
public:
    int characterReplacement(string s, int k) {

        int n(s.length());
        int i(0), j(0);                 // Sliding window pointers
        int max_win(0);                 // Maximum valid window size
        int max_freq(0);                // Max frequency of a single char in window

        unordered_map<char,int> freq;   // Frequency map for window characters

        while(j < n){

            // Include current character in the window
            freq[s[j]]++;

            // Update maximum frequency seen so far in the window
            max_freq = max(max_freq, freq[s[j]]);

            // Current window size
            int curr_win = j - i + 1;

            // If replacements needed exceed k, shrink window from left
            if(curr_win - max_freq > k){
                freq[s[i]]--;   // Remove left character
                i++;            // Move left pointer
            }

            // Recalculate window size after possible shrink
            curr_win = j - i + 1;

            // Update the maximum valid window length
            max_win = max(max_win, curr_win);

            // Expand window to the right
            j++;
        }

        return max_win;
    }
};
