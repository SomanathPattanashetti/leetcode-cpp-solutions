/*
    Leetcode / GFG Problem: Floyd Warshall Algorithm
    GFG Link: https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
    Company Tags: Samsung

    Difficulty: Medium

    Tags:
    Graph, Shortest Path, Dynamic Programming, Floyd Warshall

    ✅ Approach:
    Floyd Warshall Algorithm is used to find the shortest distance
    between every pair of vertices in a graph.

    The idea is:
    Try every node as an intermediate (via) node and check whether
    using that node gives a shorter path between i and j.

    Steps:
    1. Convert all -1 values into a large number (INF),
       because -1 means no direct path exists.
    2. Run 3 nested loops:
         - via → intermediate node
         - i   → source node
         - j   → destination node
    3. Update shortest distance:
         grid[i][j] =
         min(current distance,
             distance through via node)
    4. Convert unreachable paths back to -1.

    Time Complexity: O(V^3)
    Space Complexity: O(1)
*/

class Solution {
  public:

    void shortest_distance(vector<vector<int>>& grid) {

        int n = grid.size();

        // Step 1:
        // Replace -1 with a very large number (INF)
        // because -1 means no direct path exists
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(grid[i][j] == -1)
                    grid[i][j] = 100000;

            }
        }

        // Step 2:
        // Try every node as an intermediate (via) node
        for(int via = 0; via < n; via++) {

            for(int i = 0; i < n; i++) {

                for(int j = 0; j < n; j++) {

                    // Step 3:
                    // Update shortest path if going through
                    // 'via' gives a shorter distance
                    grid[i][j] =
                        min(grid[i][j],
                            grid[i][via] + grid[via][j]);

                }
            }
        }

        // Step 4:
        // Convert unreachable paths back to -1
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 100000)
                    grid[i][j] = -1;

            }
        }
    }
};