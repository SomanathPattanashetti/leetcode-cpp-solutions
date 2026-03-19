// Leetcode Problem: 516. Longest Palindromic Subsequence
// Link: https://leetcode.com/problems/longest-palindromic-subsequence/
// Difficulty: Medium
// Tags: Dynamic Programming, Recursion, Memoization, String

// ✅ Approach:
// We use Top-Down Dynamic Programming (Memoization).
//
// The idea is to find the longest palindromic subsequence
// between indices i and j.
//
// 🔹 If characters at both ends match (s[i] == s[j]):
//     Include both characters → 2 + solve(i+1, j-1)
//
// 🔹 If they don't match:
//     Try skipping one character from either side:
//     - solve(i, j-1)
//     - solve(i+1, j)
//     Take the maximum of both.
//
// We store results in dp[i][j] to avoid recomputation.

class Solution {
public:

    vector<vector<int>> dp;  // Memoization table

    // Recursive function to find LPS length in substring s[i...j]
    int solve(string& s, int i, int j){

        // Base Case:
        // If indices cross → no valid subsequence
        if(i > j)
            return 0;

        // If single character → palindrome of length 1
        if(i == j)
            return 1;

        // Return cached result if already computed
        if(dp[i][j] != -1)
            return dp[i][j];

        // 🔹 Case 1: Characters match
        if(s[i] == s[j])
            return dp[i][j] = 2 + solve(s, i+1, j-1);

        // 🔹 Case 2: Characters don't match
        int take_i = solve(s, i, j-1);   // Skip right character
        int take_j = solve(s, i+1, j);   // Skip left character

        // Store and return the maximum result
        return dp[i][j] = max(take_i, take_j);
    }
    
    int longestPalindromeSubseq(string s) {

        // Initialize DP table with -1 (uncomputed states)
        dp.resize(1001, vector<int>(1001, -1));

        // Solve for the entire string
        return solve(s, 0, s.length() - 1);
        
    }
};