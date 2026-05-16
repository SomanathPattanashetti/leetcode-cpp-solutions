// Leetcode Problem: 1631. Path With Minimum Effort
// Link: https://leetcode.com/problems/path-with-minimum-effort/
// Difficulty: Medium
// Tags: Graph, Dijkstra, Heap (Priority Queue), Matrix

// ✅ Approach:
// We need to find a path from top-left to bottom-right
// such that the maximum absolute height difference
// between adjacent cells is minimized.
//
// This is a shortest path problem where:
// - Each cell is a node
// - Effort between adjacent cells = absolute height difference
// - Path cost = maximum edge weight in that path
//
// We use Dijkstra’s Algorithm with a Min Heap.
//
// Instead of storing total distance,
// we store the minimum possible "maximum effort"
// required to reach each cell.
//
// At every step:
// 1. Pick the cell with the minimum effort so far
// 2. Explore all 4 directions
// 3. Calculate effort to move to neighbour
// 4. Update if we found a better path
//
// Once we reach the bottom-right cell,
// that effort is the answer.

class Solution {
public:

    // {effort, {row, col}}
    using P = pair<int, pair<int, int>>;

    // 4 possible directions: Up, Down, Right, Left
    vector<vector<int>> directions{
        {-1, 0}, {1, 0}, {0, 1}, {0, -1}
    };

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();

        // result[i][j] stores minimum effort needed
        // to reach cell (i, j)
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        // Min Heap:
        // {current_effort, {i, j}}
        priority_queue<P, vector<P>, greater<P>> pq;

        // Starting point effort = 0
        result[0][0] = 0;
        pq.push({0, {0, 0}});

        // Function to check valid cell
        auto isSafe = [&](int i, int j){
            return i >= 0 && i < m && j >= 0 && j < n;
        };

        while(!pq.empty()){

            // Get cell with minimum effort
            auto [diff, co_ord] = pq.top();
            auto [i, j] = co_ord;

            pq.pop();

            // If destination reached, return answer
            if(i == m - 1 && j == n - 1)
                return diff;

            // Explore all 4 directions
            for(auto& dir : directions){

                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(isSafe(i_, j_)){

                    // Current edge effort
                    int abs_diff =
                        abs(heights[i][j] - heights[i_][j_]);

                    // Path effort =
                    // maximum effort seen so far
                    int max_diff = max(diff, abs_diff);

                    // If better path found
                    if(result[i_][j_] > max_diff){

                        result[i_][j_] = max_diff;

                        // Push updated effort into heap
                        pq.push({max_diff, {i_, j_}});
                    }
                }
            }
        }

        // Final minimum effort
        return result[m - 1][n - 1];
    }
};