// Leetcode Problem: 743. Network Delay Time
// Link: https://leetcode.com/problems/network-delay-time/
// Difficulty: Medium
// Tags: Graph, Shortest Path, Dijkstra, Heap (Priority Queue)

// ✅ Approach:
// We use Dijkstra’s Algorithm to find the shortest time
// required for the signal to reach all nodes.
//
// The graph is directed:
// u -> v with weight w
//
// Steps:
// 1. Create an adjacency list from the given edges.
// 2. Use a min-heap (priority queue) to always process
//    the node with the minimum distance.
// 3. Store shortest distances in the result array.
// 4. Relax adjacent edges:
//      if(current_distance + edge_weight < stored_distance)
//          update the distance.
// 5. If any node remains unreachable (INT_MAX),
//    return -1.
// 6. Otherwise, return the maximum distance because
//    the signal must reach all nodes.

class Solution {
public:

    using P = pair<int, int>;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Adjacency List:
        // node -> {adjacent_node, weight}
        unordered_map<int, vector<P>> adj;

        // Build Directed Graph
        for(auto& time : times){

            int u = time[0];
            int v = time[1];
            int w = time[2];

            adj[u].push_back({v, w});
        }

        // Stores shortest distance from source node k
        vector<int> result(n + 1, INT_MAX);

        // Distance to source itself is 0
        result[k] = 0;

        // Min-Heap:
        // {distance, node}
        priority_queue<P, vector<P>, greater<P>> pq;

        // Start from source node
        pq.push({0, k});

        // Dijkstra Algorithm
        while(!pq.empty()){

            auto [d, node] = pq.top();
            pq.pop();

            // Skip outdated entries
            if(d > result[node]) continue;

            // Explore all neighbors
            for(auto [adj_node, dist] : adj[node]){

                // Relaxation Step
                if(d + dist < result[adj_node]){

                    // Update shortest distance
                    result[adj_node] = d + dist;

                    // Push updated distance into heap
                    pq.push({d + dist, adj_node});
                }
            }
        }

        // If any node is unreachable -> return -1
        // Else return maximum shortest distance
        return any_of(begin(result) + 1, end(result),
                      [](int x){ return x == INT_MAX; })
               ? -1
               : *max_element(begin(result) + 1, end(result));
    }
};