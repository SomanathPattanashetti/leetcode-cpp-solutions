// GeeksforGeeks Problem: Detect Cycle in an Undirected Graph
// Difficulty: Medium
// Tags: Graph, BFS, Cycle Detection

// ✅ Approach:
// Use BFS (Breadth-First Search) to detect a cycle in an undirected graph.
//
// Key Idea:
// - Maintain a queue storing {currentNode, parentNode}.
// - If we visit a node that is already visited AND it is not the parent,
//   then a cycle exists.
//
// Steps:
// 1. Build adjacency list from edges.
// 2. Use a visited[] array to track visited nodes.
// 3. For each unvisited node, perform BFS.
// 4. During BFS, if we encounter a visited node that is NOT the parent → Cycle found.

class Solution {
  public:
    
    // Using pair: {node, parent}
    using P = pair<int, int>;
    
    // Function to detect cycle starting from node 'u'
    bool bfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited) {
        
        // Queue stores {current node, parent node}
        queue<P> que;
        que.push({u, -1});  // -1 means no parent (start node)
        visited[u] = true;
        
        while(!que.empty()) {
            
            auto [u, parent] = que.front();
            que.pop();
            
            // Visit all neighbors of current node
            for(auto& v : adj[u]) {
                
                // Case 1: If neighbor is not visited → normal BFS
                if(!visited[v]) {
                    visited[v] = true;
                    que.push({v, u});  // mark current node as parent
                }
                // Case 2: If visited and not parent → Cycle detected
                else if(v != parent) {
                    return true;
                }
            }
        }
        
        return false; // No cycle found from this component
    }
    
    // Main function to check cycle in the entire graph
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<int>> adj;
        
        // Build adjacency list
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);  // Undirected graph
        }
        
        vector<bool> visited(V, false);
        
        // Check all components (graph may be disconnected)
        for(int u = 0; u < V; u++) {
            if(!visited[u] && bfs(adj, u, visited))
                return true;  // Cycle found
        }
        
        return false; // No cycle in any component
    }
};