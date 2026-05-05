// Leetcode / GFG Problem: Dijkstra Algorithm (Shortest Path)
// Difficulty: Medium
// Tags: Graph, Greedy, Heap (Priority Queue)

// ✅ Approach:
// This problem gives us a graph in the form of an edge list.
// Each edge is represented as: [u, v, w] → edge between u and v with weight w.
//
// Since the graph is weighted, we cannot use BFS.
// Instead, we use Dijkstra’s Algorithm to find the shortest path from source node.
//
// 🔹 Steps:
// 1. Convert edge list → adjacency list for efficient traversal
// 2. Use a Min Heap (Priority Queue) to always process the node with smallest distance
// 3. Initialize distance array with INT_MAX
// 4. Start from source node with distance = 0
// 5. Relax edges (update distances if shorter path is found)
// 6. Skip outdated entries to optimize performance

class Solution {
  public:
    
    using P = pair<int, int>; // {distance, node}
    
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // 🔥 Step 1: Build adjacency list
        // Since graph is undirected, we add edges in both directions
        vector<vector<P>> adj(V);
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // 🔥 Step 2: Initialize distance array
        // Initially, all nodes are at infinite distance
        vector<int> dist(V, INT_MAX);
        
        // Min Heap → stores {distance, node}
        priority_queue<P, vector<P>, greater<P>> pq;
        
        // Distance of source node = 0
        dist[src] = 0;
        pq.push({0, src});
        
        // 🔥 Step 3: Process nodes
        while(!pq.empty()){
            
            // Get node with minimum distance
            auto [d, node] = pq.top();
            pq.pop();
            
            // 🔹 Skip outdated entries
            // If we already found a better path, ignore this one
            if(d > dist[node]) continue;
            
            // 🔹 Traverse all adjacent nodes
            for(auto [adjNode, wt] : adj[node]){
                
                // Relaxation step:
                // Check if current path gives shorter distance
                if(d + wt < dist[adjNode]){
                    dist[adjNode] = d + wt;
                    
                    // Push updated distance into heap
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        // 🔥 Final result: shortest distances from source
        return dist;
    }
};