// Leetcode Problem: 1578. Minimum Time to Make Rope Colorful
// Link: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
// Difficulty: Medium
// Tags: String, Greedy, Array

// ✅ Approach:
// We need to remove balloons so that no two adjacent balloons have the same color.
// If consecutive balloons have the same color, we should keep the one with the maximum removal time
// and remove the others with smaller times.
//
// Greedy Idea:
// For every group of same-colored balloons:
// - Add the smaller time to the answer
// - Keep the larger time for future comparison
//
// This ensures minimum total removal cost.

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {

        int n = colors.length();   // Total number of balloons

        int time = 0;   // Stores minimum total removal time
        int prev = 0;   // Stores the maximum time in the current same-color group

        for(int i = 0; i < n; i++) {

            // If current balloon color is different from previous,
            // start a new group, so reset prev
            if(i > 0 && colors[i] != colors[i - 1])
                prev = 0;

            int curr = neededTime[i];   // Current balloon removal time

            // Add the smaller time because one balloon must be removed
            // when there is a duplicate color
            time += min(prev, curr);

            // Keep the maximum time balloon in the group
            prev = max(prev, curr);
        }

        return time;   // Minimum total time required
    }
};