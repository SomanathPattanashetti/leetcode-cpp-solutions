// Leetcode Problem: 2938. Separate Black and White Balls
// Link: https://leetcode.com/problems/separate-black-and-white-balls/
// Difficulty: Medium
// Tags: String, Greedy, Counting

// ✅ Approach:
// We need to count the minimum number of adjacent swaps required
// to move all '0's (white balls) to the left and all '1's (black balls) to the right.
//
// Key Observation:
// Each time we encounter a '0', it needs to cross all the '1's that appeared before it.
// The number of swaps needed is equal to the count of previous '1's.
//
// So, we:
// 1. Traverse the string from left to right.
// 2. Keep track of how many '1's (black balls) we've seen so far.
// 3. Whenever we see a '0', add the count of previous '1's to the swap count.

class Solution {
public:
    long long minimumSteps(string s) {

        int black = 0;        // Counts number of '1's seen so far
        long long swaps = 0; // Total number of swaps required

        // Traverse each character in the string
        for (auto& ch : s) {

            // If current character is '1', increment black count
            if (ch == '1') {
                black++;
            }
            // If current character is '0'
            // it needs to cross all previous '1's
            else {
                swaps += black;
            }
        }

        // Return total swaps needed
        return swaps;
    }
};
