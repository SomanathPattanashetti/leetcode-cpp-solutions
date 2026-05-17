/*
    Leetcode / GFG Problem: Bellman-Ford Algorithm
    Link: https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
    Difficulty: Medium
    Tags: Graph, Shortest Path

    ✅ Approach:
    Bellman-Ford Algorithm is used to find the shortest distance
    from a source node to all other nodes in a graph.

    Unlike Dijkstra’s Algorithm, Bellman-Ford can handle
    negative weight edges.

    Step 1:
    Initialize all distances as INF (1e8 here),
    and mark source distance as 0.

    Step 2:
    Relax all edges exactly (V - 1) times.
    Relaxation means:
    if(dist[u] + weight < dist[v])
        update dist[v]

    Why (V - 1) times?
    Because the longest possible shortest path in a graph
    can contain at most (V - 1) edges.

    Step 3:
    Perform one extra iteration to detect
    a negative weight cycle.

    If we can still relax an edge,
    then a negative cycle exists in the graph.

    Time Complexity: O(V * E)
    Space Complexity: O(V)
*/

class Solution {
  public:

    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {

        // Store shortest distance from source to every node
        vector<int> result(V, 1e8);

        // Distance to source node is always 0
        result[S] = 0;

        // Relax all edges (V - 1) times
        for(int c = 1; c <= V - 1; c++) {

            for(auto &edge : edges) {

                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                // Relaxation condition
                if(result[u] != 1e8 && result[u] + w < result[v]) {
                    result[v] = result[u] + w;
                }
            }
        }

        // 🔹 Check for Negative Weight Cycle
        for(auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            // If relaxation still possible,
            // negative cycle exists
            if(result[u] != 1e8 && result[u] + w < result[v]) {
                return {-1};
            }
        }

        // Return shortest distances
        return result;
    }
};