// Leetcode Problem: 56. Merge Intervals
// Link: https://leetcode.com/problems/merge-intervals/
// Difficulty: Medium
// Tags: Array, Sorting, Greedy

// ✅ Approach:
// 1. First, sort the intervals based on their start time.
// 2. Initialize a variable `prev` with the first interval.
// 3. Traverse remaining intervals one by one:
//    - If the current interval overlaps with `prev`
//      (i.e., prev[1] >= current[0]):
//         → Merge them by updating prev[1] to the maximum end.
//    - Otherwise:
//         → Store `prev` in result and update `prev` to current interval.
// 4. After traversal, push the last `prev` interval into the result.
// 5. Return the merged intervals list.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Step 1: Sort intervals by starting time
        sort(begin(intervals), end(intervals));

        vector<vector<int>> res;  // Stores merged intervals
        int n = intervals.size();

        // Step 2: Initialize with the first interval
        vector<int> prev = intervals[0];

        // Step 3: Traverse remaining intervals
        for(int i = 1; i < n; i++) {

            // Overlapping case
            if(prev[1] >= intervals[i][0]) {
                // Merge intervals
                prev[1] = max(prev[1], intervals[i][1]);
            }
            else {
                // No overlap, store previous interval
                res.push_back(prev);
                prev = intervals[i];
            }
        }

        // Step 4: Add the last interval
        res.push_back(prev);

        // Step 5: Return result
        return res;
    }
};
