/*
    LeetCode 1584: Min Cost to Connect All Points
    Topic: Minimum Spanning Tree (Prim’s Algorithm)

    Difficulty: Medium

    Tags:
    Graph, MST, Prim's Algorithm, Greedy, Priority Queue

    ✅ Approach:
    This solution uses Prim’s Algorithm to find the
    Minimum Cost required to connect all points.

    Each point acts like a graph node.

    Cost between two points:
    Manhattan Distance

    Formula:
    |x1 - x2| + |y1 - y2|

    Goal:
    Connect all points with minimum total cost
    without forming cycles.

    Idea:
    1. Treat every point as a node.
    2. Create edges between every pair of points
       using Manhattan distance.
    3. Apply Prim’s Algorithm to build MST.
    4. Always pick the minimum cost edge
       connecting a new unvisited node.

    Steps:
    1. Build adjacency list for all points.
    2. Use Min Heap (Priority Queue)
       to get minimum weight edge.
    3. Start from node 0 with cost 0.
    4. Skip already visited nodes.
    5. Otherwise:
         - Add edge cost to answer
         - Mark node visited
    6. Push all unvisited adjacent nodes
       into priority queue.
    7. Continue until all nodes are connected.

    Time Complexity:
    Building Graph: O(V²)

    Prim’s Algorithm:
    O(E log V)

    Since:
    E = V²

    Total:
    O(V² log V)

    Space Complexity:
    O(V²)
*/

class Solution {
public:
    
    using P = pair<int, int>;

    int primsAlgorithm(vector<vector<P>>& adj, int V){

        // Visited array to avoid cycles
        vector<bool> visited(V, false);

        // Min Heap:
        // {weight, node}
        priority_queue<P, vector<P>, greater<P>> pq;

        // Start from node 0
        pq.push({0, 0});

        int sum = 0;

        while(!pq.empty()){

            auto [d, node] = pq.top();
            pq.pop();

            // Skip if already visited
            if(visited[node])
                continue;

            // Add current edge weight to MST sum
            sum += d;

            // Mark node visited
            visited[node] = true;

            // Traverse adjacent nodes
            for(auto [adj_node, adj_node_wt] : adj[node]){

                // Push only unvisited nodes
                if(!visited[adj_node]){
                    pq.push({adj_node_wt, adj_node});
                }
            }
        }

        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {

        int V = points.size();

        // Adjacency List:
        // node -> {adjacent node, weight}
        vector<vector<P>> adj(V);

        // Build graph using Manhattan Distance
        for(int i = 0; i < V; i++){

            for(int j = i + 1; j < V; j++){

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                // Manhattan Distance
                int d = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }

        // Apply Prim's Algorithm
        return primsAlgorithm(adj, V);
    }
};