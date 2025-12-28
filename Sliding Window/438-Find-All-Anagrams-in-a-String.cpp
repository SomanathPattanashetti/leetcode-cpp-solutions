// Leetcode Problem: 438. Find All Anagrams in a String
// Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Difficulty: Medium
// Tags: Sliding Window, Hashing, String

// ✅ Approach:
// Use the Sliding Window technique with a frequency array.
// 
// Steps:
// 1. Store character frequencies of pattern `pat` in a freq array.
// 2. Use two pointers (i, j) to maintain a window of size `k` (length of pat).
// 3. As we expand the window, decrement the frequency of current character.
// 4. When window size becomes `k`:
//    - Check if all frequencies are zero → an anagram found.
//    - Slide the window by restoring the left character's frequency.
// 5. Store all starting indices where anagrams are found.

class Solution {
public:

    // Helper function to check if all frequencies are zero
    bool allZeros(vector<int>& freq) {

        // If any character count is non-zero, not an anagram
        for(auto& i : freq) {
            if(i != 0)
                return false;
        }

        // All frequencies are zero → valid anagram
        return true;
    }

    vector<int> findAnagrams(string txt, string pat) {

        int n = txt.length();   // Length of text
        int k = pat.length();   // Length of pattern

        vector<int> freq(26, 0);

        // Store frequency of characters in pattern
        for(auto& ch : pat)
            freq[ch - 'a']++;

        int i = 0, j = 0;       // Sliding window pointers
        vector<int> res;       // Stores starting indices of anagrams

        while(j < n) {

            // Include current character into the window
            freq[txt[j] - 'a']--;

            // When window size equals pattern length
            if(j - i + 1 == k) {

                // Check if current window is an anagram
                if(allZeros(freq)) {
                    res.push_back(i);
                }

                // Remove the leftmost character from window
                freq[txt[i] - 'a']++;
                i++;
            }

            // Expand window
            j++;
        }

        return res;
    }
};
