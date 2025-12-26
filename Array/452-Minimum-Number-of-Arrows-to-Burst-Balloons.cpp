// Leetcode Problem: 452. Minimum Number of Arrows to Burst Balloons
// Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
// Difficulty: Medium
// Tags: Greedy, Sorting, Intervals

// ✅ Approach:
// This problem is solved using a **Greedy Interval Merging strategy**.
//
// Idea:
// Each balloon is represented as an interval [start, end].
// One arrow can burst all balloons whose intervals overlap at a point.
//
// Steps:
// 1. Sort all balloons based on their starting coordinate.
// 2. Start with the first balloon and assume we shoot one arrow.
// 3. For every next balloon:
//    - If its start is greater than the end of the previous overlapping interval,
//      we need a new arrow.
//    - Otherwise, we update the overlapping range by shrinking it to the common intersection.
//
// Key Insight:
// Always keep the **minimum possible overlapping range** so that one arrow can
// burst as many balloons as possible.

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        // Sort balloons by starting point
        sort(begin(points), end(points));

        int n = points.size();

        // Store the current overlapping interval
        vector<int> prev = points[0];

        // At least one arrow is needed
        int count = 1;

        // Traverse remaining balloons
        for(int i = 1; i < n; i++) {

            int curr_StartPt = points[i][0];
            int curr_EndPt   = points[i][1];

            int prev_StartPt = prev[0];
            int prev_EndPt   = prev[1];

            // 🔹 Case 1: No overlap → need a new arrow
            if(curr_StartPt > prev_EndPt) {
                count++;               // Shoot a new arrow
                prev = points[i];      // Update interval
            }
            // 🔹 Case 2: Overlap exists → adjust intersection
            else {
                prev[0] = max(prev_StartPt, curr_StartPt);
                prev[1] = min(prev_EndPt, curr_EndPt);
            }
        }

        return count;  // Minimum arrows required
    }
};
