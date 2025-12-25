// Leetcode Problem: 57. Insert Interval
// Link: https://leetcode.com/problems/insert-interval/
// Difficulty: Medium
// Tags: Array, Interval, Greedy

// ✅ Approach:
// We are given a list of non-overlapping intervals sorted by start time.
// We need to insert a new interval and merge if required.
//
// Idea:
// Traverse the existing intervals and compare each one with newInterval.
//
// There are 3 possible cases:
// 1️⃣ Current interval ends before newInterval starts
//     → No overlap, directly add current interval to result
//
// 2️⃣ Current interval starts after newInterval ends
//     → No overlap and newInterval should be placed before this
//     → Break the loop and insert newInterval
//
// 3️⃣ Overlapping case
//     → Merge current interval with newInterval
//     → Update newInterval's start and end
//
// After traversal:
// - Push the merged newInterval
// - Add remaining intervals as it is

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> res;   // Resultant intervals
        int n = intervals.size();
        int i = 0;

        // Traverse all intervals
        while (i < n) {

            // 🔹 Case 1: Current interval is completely before newInterval
            if (newInterval[0] > intervals[i][1]) {
                res.push_back(intervals[i]);
            }

            // 🔹 Case 2: Current interval is completely after newInterval
            // newInterval should be placed before this interval
            else if (newInterval[1] < intervals[i][0]) {
                break;
            }

            // 🔹 Case 3: Overlapping intervals → Merge them
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }

            i++;
        }

        // Insert the merged newInterval
        res.push_back(newInterval);

        // Add remaining intervals after newInterval
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};
