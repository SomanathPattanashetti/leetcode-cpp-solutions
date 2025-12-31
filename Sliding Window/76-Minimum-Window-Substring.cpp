// Leetcode Problem: 76. Minimum Window Substring
// Link: https://leetcode.com/problems/minimum-window-substring/
// Difficulty: Hard
// Tags: String, Sliding Window, Hash Map, Two Pointers

// ✅ Approach:
// Use Sliding Window technique with two pointers (i and j).
// We expand the window using j to include characters.
// We shrink the window using i when all required characters are present.
//
// Steps:
// 1. Store frequency of all characters in string `t` using a hash map.
// 2. Maintain a `required_count` to track how many characters are still needed.
// 3. Expand the window by moving `j` and updating counts.
// 4. When `required_count` becomes 0, try to shrink the window from left (`i`)
//    to find the minimum valid window.
// 5. Keep updating the minimum window length and starting index.

class Solution {
public:
    string minWindow(string s, string t) {

        // If t is longer than s, no valid window is possible
        if(t.length() > s.length())
            return "";

        unordered_map<char, int> mp;   // Stores frequency of characters in t

        int n = s.length();
        int i = 0, j = 0;              // Sliding window pointers
        int start_i = 0;               // Starting index of minimum window

        // Store frequency of characters of t
        for(auto& ch : t)
            mp[ch]++;

        int required_count = t.length();  // Total characters still needed
        int min_win_len = INT_MAX;         // Minimum window length found

        // Expand the window using j pointer
        while(j < n){

            // If current character is needed, reduce required_count
            if(mp[s[j]] > 0)
                required_count--;

            // Decrease frequency of current character
            mp[s[j]]--;

            // When all characters are found, try to shrink the window
            while(required_count == 0){

                int curr_win_len = j - i + 1;

                // Update minimum window
                if(min_win_len > curr_win_len){
                    min_win_len = curr_win_len;
                    start_i = i;
                }

                // Restore frequency of character at i
                mp[s[i]]++;

                // If character becomes required again, increase required_count
                if(mp[s[i]] > 0)
                    required_count++;

                // Move left pointer to shrink window
                i++;
            }

            // Move right pointer to expand window
            j++;
        }

        // If no valid window found, return empty string
        // Else return the minimum window substring
        return min_win_len == INT_MAX ? "" : s.substr(start_i, min_win_len);
    }
};
