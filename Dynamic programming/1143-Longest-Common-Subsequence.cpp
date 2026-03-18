// Leetcode Problem: 1143. Longest Common Subsequence
// Link: https://leetcode.com/problems/longest-common-subsequence/
// Difficulty: Medium
// Tags: Dynamic Programming, Recursion, Memoization

// ✅ Approach:
// We use Recursion + Memoization (Top-Down DP)
//
// Idea:
// Compare characters of both strings one by one.
//
// 🔹 If characters match:
//    Include it in LCS and move both pointers forward
//
// 🔹 If characters do NOT match:
//    Try both possibilities:
//      1. Move pointer in s1
//      2. Move pointer in s2
//    Take the maximum of both choices
//
// We store results in DP to avoid recomputation.

class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    // Recursive function to find LCS
    int solve(string& s1, string& s2, int i, int j){

        // Base Case:
        // If any string is fully traversed, LCS = 0
        if(i >= n || j >= m)
            return 0;

        // If already computed, return stored result
        if(dp[i][j] != -1)
            return dp[i][j];

        // 🔹 Case 1: Characters match
        // Include this character and move both pointers
        if(s1[i] == s2[j])
            return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1);

        // 🔹 Case 2: Characters do NOT match
        // Try skipping one character from either string
        return dp[i][j] = max(
            solve(s1, s2, i + 1, j),  // Skip from s1
            solve(s1, s2, i, j + 1)   // Skip from s2
        );
    }

    int longestCommonSubsequence(string s1, string s2) {

        n = s1.length();
        m = s2.length();

        // Initialize DP table with -1 (uncomputed states)
        dp.resize(1001, vector<int>(1001, -1));

        // Start recursion from index (0,0)
        return solve(s1, s2, 0, 0);
    }
};