// Leetcode / GFG Problem: Dijkstra Algorithm (Shortest Path)
// Difficulty: Medium
// Tags: Graph, Greedy, Set

// ✅ Approach:
// This problem gives us a graph in the form of an edge list.
// Each edge is represented as: [u, v, w] → edge between u and v with weight w.
//
// Since the graph is weighted, we cannot use BFS.
// Instead, we use Dijkstra’s Algorithm to find the shortest path from source node.
//
// 🔹 Difference from Priority Queue:
// Instead of a min-heap, we use a set.
// Set automatically keeps elements sorted and allows deletion of outdated entries.
//
// 🔹 Steps:
// 1. Convert edge list → adjacency list for efficient traversal
// 2. Use a set to always fetch the node with smallest distance
// 3. Initialize distance array with INT_MAX
// 4. Start from source node with distance = 0
// 5. Relax edges (update distances if shorter path is found)
// 6. Remove old entries from set before inserting updated values

class Solution {
  public:
    
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // 🔥 Step 1: Build adjacency list
        // Since graph is undirected, we add edges in both directions
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // 🔥 Step 2: Initialize distance array
        vector<int> dist(V, INT_MAX);
        
        // Set → stores {distance, node}
        set<pair<int,int>> st;
        
        // Distance of source node = 0
        dist[src] = 0;
        st.insert({0, src});
        
        // 🔥 Step 3: Process nodes
        while(!st.empty()){
            
            // Get node with minimum distance
            auto it = st.begin();
            int d = it->first;
            int node = it->second;
            st.erase(it);
            
            // 🔹 Traverse all adjacent nodes
            for(auto [adjNode, wt] : adj[node]){
                
                // Relaxation step
                if(d + wt < dist[adjNode]){
                    
                    // 🔹 Remove old entry if it exists
                    if(dist[adjNode] != INT_MAX){
                        st.erase({dist[adjNode], adjNode});
                    }
                    
                    // Update distance
                    dist[adjNode] = d + wt;
                    
                    // Insert updated value
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        // 🔥 Final result: shortest distances from source
        return dist;
    }
};