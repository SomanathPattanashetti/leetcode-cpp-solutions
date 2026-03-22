// Leetcode Problem: 518. Coin Change II
// Link: https://leetcode.com/problems/coin-change-ii/
// Difficulty: Medium
// Tags: Dynamic Programming, Recursion, Memoization

// ✅ Approach:
// We use Recursion + Memoization to count the number of ways
// to make the given amount using the given coins.
//
// At each coin index, we have 2 choices:
//  1. Take the current coin
//     - Since we can use a coin unlimited times, we stay at the same index
//     - Reduce the amount by coins[idx]
//  2. Skip the current coin
//     - Move to the next coin index
//
// The answer is the sum of both choices.
//
// Memoization is used to store already computed states:
// dp[amount][idx] = number of ways to make 'amount' starting from coin index 'idx'

class Solution {
public:

    vector<vector<int>> dp;

    // Recursive function to count ways
    int solve(vector<int>& coins, int amount, int idx){

        // Base Case:
        // If we have checked all coins and still amount is not 0,
        // then no valid way is possible
        if(idx >= coins.size())
            return 0;

        // Base Case:
        // If amount becomes 0, we found one valid way
        if(amount == 0)
            return 1;

        // If already computed, return stored result
        if(dp[amount][idx] != -1)
            return dp[amount][idx];

        // If current coin value is greater than amount,
        // we cannot take it, so skip to next coin
        if(coins[idx] > amount)
            return dp[amount][idx] = solve(coins, amount, idx + 1);
        
        // 🔹 Choice 1: Take current coin
        // Stay at same index because same coin can be used again
        int take = solve(coins, amount - coins[idx], idx);

        // 🔹 Choice 2: Skip current coin
        // Move to next coin
        int skip = solve(coins, amount, idx + 1);

        // Store and return total ways
        return dp[amount][idx] = take + skip;
    }
    
    int change(int amount, vector<int>& coins) {

        // DP table initialization
        // amount can go up to 5000
        // coins size can go up to 300
        dp.resize(5001, vector<int>(301, -1));

        // Start recursion from index 0
        return solve(coins, amount, 0);
        
    }
};