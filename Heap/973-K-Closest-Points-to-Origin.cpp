// Leetcode Problem: 973. K Closest Points to Origin
// Link: https://leetcode.com/problems/k-closest-points-to-origin/
// Difficulty: Medium
// Tags: Heap (Priority Queue), Sorting, Geometry

// ✅ Approach:
// We need the K points closest to the origin (0,0).
// Distance formula: √(x² + y²)
// But square root is expensive and unnecessary for comparison,
// so we compare using: (x² + y²)
//
// We use a MAX HEAP of size K.
// Why Max Heap?
//  - We keep only K closest points
//  - The farthest among the K should be removed first
//
// Steps:
// 1. Traverse all points
// 2. Push each point with its distance into heap
// 3. If heap size exceeds K → remove the farthest (top of max heap)
// 4. Finally heap contains exactly K closest points

class Solution {
public:

    // Tuple stores -> {distance, x, y}
    using T = tuple<int, int, int>;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // Max Heap (default priority_queue is max heap)
        priority_queue<T> pq;

        // Step 1: Process every point
        for(auto& point : points){

            int x = point[0];
            int y = point[1];

            // Calculate squared distance from origin
            int distance = (x * x) + (y * y);

            // Push into heap
            pq.push({distance, x, y});

            // Maintain heap size = k
            // Remove farthest point if exceeded
            if(pq.size() > k)
                pq.pop();
        }

        // Step 2: Extract answer
        vector<vector<int>> res;

        while(!pq.empty()){
            auto& [dist, x, y] = pq.top();
            res.push_back({x,y});
            pq.pop();
        }

        return res;
    }
};