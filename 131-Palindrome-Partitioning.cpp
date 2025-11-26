// Leetcode Problem: 131. Palindrome Partitioning
// Link: https://leetcode.com/problems/palindrome-partitioning/
// Difficulty: Medium
// Tags: String, Backtracking, DFS

// ✅ Approach:
// Use Backtracking to generate all possible partitions of the string.
//
// At each index, try to cut the string into a substring s[idx...i].
// BUT — we only proceed if that substring is a palindrome.
//
// Steps:
// 1️⃣ Check every possible substring starting at `idx`.
// 2️⃣ If substring s[idx..i] is a palindrome, include it in temp.
// 3️⃣ Recursively solve for the remaining string starting at i+1.
// 4️⃣ When idx reaches end of string, we store the partition.
//
// A helper function `isPalindrome()` checks if a substring is palindrome.
//

class Solution {
public:
    vector<vector<string>> res;  // Stores all valid palindrome partitions
    int n;

    // 🔍 Function to check if s[i..j] is a palindrome
    bool isPalindrome(string& s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    // Recursive function to generate palindrome partitions
    void solve(string& s, int idx, vector<string>& temp) {

        // Base Case:
        // If index reaches the end, push the current partition
        if(idx >= n) {
            res.push_back(temp);
            return;
        }

        // Try all cuts from idx to n-1
        for(int i = idx; i < n; i++) {

            // Check if substring s[idx..i] is a palindrome
            if(isPalindrome(s, idx, i)) {

                // Add this substring to the current path
                temp.push_back(s.substr(idx, i - idx + 1));

                // Recur for the remaining substring
                solve(s, i + 1, temp);

                // Backtrack: remove the last added substring
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<string> temp;

        solve(s, 0, temp);   // Start from index 0

        return res;          // Contains all palindrome partitions
    }
};
