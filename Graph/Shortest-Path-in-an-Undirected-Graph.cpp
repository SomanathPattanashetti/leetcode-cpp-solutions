// GFG Problem: Shortest Path in an Undirected Graph
// Difficulty: Medium
// Tags: Graph, Dijkstra Algorithm, Priority Queue

// ✅ Approach:
// Since the graph is weighted, BFS cannot guarantee the shortest path.
// So, we use Dijkstra’s Algorithm with a Min Heap (Priority Queue).
//
// Steps:
// 1. Create an adjacency list to store graph connections.
// 2. Use a distance array to store the shortest distance from node 1.
// 3. Use a parent array to reconstruct the shortest path.
// 4. Start Dijkstra from node 1.
// 5. Whenever we find a shorter path to a node,
//    update its distance and parent.
// 6. After Dijkstra finishes, backtrack using the parent array
//    to rebuild the path from n → 1.
// 7. Reverse the path and return:
//      [shortest_distance, path nodes...]

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {

        // 🔹 Adjacency List
        // Stores: node -> {adjacent node, edge weight}
        vector<pair<int,int>> adj[n + 1];

        for(auto &edge : edges) {

            int u  = edge[0];
            int v  = edge[1];
            int wt = edge[2];

            // Undirected Graph
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // 🔹 Distance Array
        // Stores shortest distance from node 1
        vector<int> dist(n + 1, 1e9);

        // 🔹 Parent Array
        // Used for path reconstruction
        vector<int> parent(n + 1);

        // Initially every node is its own parent
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // 🔹 Min Heap -> {distance, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        // Distance to source node is 0
        dist[1] = 0;

        pq.push({0, 1});

        // 🔹 Dijkstra Algorithm
        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int d    = it.first;
            int node = it.second;

            // Traverse all adjacent nodes
            for(auto &nbr : adj[node]) {

                int adjNode = nbr.first;
                int edgeWt  = nbr.second;

                // Relaxation Step
                // If a shorter path is found
                if(d + edgeWt < dist[adjNode]) {

                    dist[adjNode] = d + edgeWt;

                    pq.push({dist[adjNode], adjNode});

                    // Store parent for path reconstruction
                    parent[adjNode] = node;
                }
            }
        }

        // 🔹 No Path Exists
        if(dist[n] == 1e9)
            return {-1};

        // 🔹 Reconstruct Path
        vector<int> path;

        int node = n;

        // Move backwards using parent array
        while(parent[node] != node) {

            path.push_back(node);

            node = parent[node];
        }

        // Push source node
        path.push_back(1);

        // Reverse to get path from 1 → n
        reverse(path.begin(), path.end());

        // 🔹 Final Answer
        // First element = shortest distance
        vector<int> ans;

        ans.push_back(dist[n]);

        // Store all path nodes
        for(auto x : path) {
            ans.push_back(x);
        }

        return ans;
    }
};