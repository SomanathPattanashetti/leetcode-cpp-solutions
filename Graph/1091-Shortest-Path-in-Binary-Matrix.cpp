// Leetcode Problem: 1091. Shortest Path in Binary Matrix
// Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Difficulty: Medium
// Tags: Graph, BFS, Dijkstra, Matrix, Shortest Path

// ✅ Approach:
// This problem asks us to find the shortest path
// from the top-left cell (0,0) to the bottom-right cell.
//
// We can move in 8 possible directions:
//  up, down, left, right, and 4 diagonals.
//
// Since every move has equal cost (1),
// BFS is the optimal solution.
// However, here we solve it using Dijkstra Algorithm.
//
// 🔹 Idea:
// - Use a Min Heap (Priority Queue) to always process
//   the cell with the minimum distance.
// - Maintain a result[][] array where:
//      result[i][j] = shortest distance to reach cell (i,j)
// - If we find a shorter path to a neighboring cell,
//   update the distance and push it into the heap.
//
// If destination cannot be reached, return -1.

class Solution {
public:

    // P = {distance, {row, col}}
    using P = pair<int, pair<int, int>>;

    // 8 possible directions
    vector<vector<int>> directions{
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {1, -1}, {-1, -1}, {-1, 1}
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Base Case:
        // If source or destination is blocked,
        // path is impossible
        if(m == 0 || n == 0 ||
           grid[0][0] == 1 ||
           grid[m-1][n-1] == 1)
            return -1;

        // result[i][j] stores shortest distance
        // to reach cell (i,j)
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        // Min Heap:
        // {distance, {row, col}}
        priority_queue<P, vector<P>, greater<P>> pq;

        // Start from source cell
        pq.push({0, {0, 0}});

        result[0][0] = 0;

        // Function to check valid cell
        auto isSafe = [&](int i, int j) {
            return (i >= 0 && i < m &&
                    j >= 0 && j < n);
        };

        // Dijkstra Algorithm
        while(!pq.empty()) {

            // Get cell with minimum distance
            auto [d, co_ord] = pq.top();
            auto [i, j] = co_ord;

            pq.pop();

            // Cost of moving to adjacent cell
            int dist = 1;

            // Explore all 8 directions
            for(auto& dir : directions) {

                int i_ = i + dir[0];
                int j_ = j + dir[1];

                // Check:
                // 1. Cell is inside boundary
                // 2. Cell is not blocked
                // 3. Found shorter distance
                if(isSafe(i_, j_) &&
                   grid[i_][j_] == 0 &&
                   d + dist < result[i_][j_]) {

                    // Update shortest distance
                    result[i_][j_] = d + dist;

                    // Push updated distance into heap
                    pq.push({d + dist, {i_, j_}});
                }
            }
        }

        // If destination was never reached
        if(result[m-1][n-1] == INT_MAX)
            return -1;

        // +1 because source cell is also counted
        return result[m-1][n-1] + 1;
    }
};