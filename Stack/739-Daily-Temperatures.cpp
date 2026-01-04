// Leetcode Problem: 739. Daily Temperatures
// Link: https://leetcode.com/problems/daily-temperatures/
// Difficulty: Medium
// Tags: Array, Stack, Monotonic Stack

// ✅ Approach:
// Use a Monotonic Decreasing Stack to keep track of indices
// of days with higher temperatures ahead.
//
// We traverse the array from right to left so that the stack
// always contains future days.
//
// For each day:
//  - Remove all indices from the stack whose temperature
//    is less than or equal to the current day's temperature
//  - The top of the stack (if any) gives the next warmer day
//  - The difference of indices gives the number of days to wait
//
// If no warmer day exists, the answer is 0.

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();

        stack<int> stk;          // Stores indices of days
        vector<int> res(n);      // Result array

        // Traverse from the last day to the first day
        for(int i = n - 1; i >= 0; i--) {

            // Pop all days that are not warmer than current day
            while(!stk.empty() && temperatures[i] >= temperatures[stk.top()]) {
                stk.pop();
            }

            // If stack is empty, no warmer day exists
            if(stk.empty()) {
                res[i] = 0;
            }
            // Otherwise, distance to next warmer day
            else {
                res[i] = stk.top() - i;
            }

            // Push current day's index onto the stack
            stk.push(i);
        }

        return res;
    }
};
