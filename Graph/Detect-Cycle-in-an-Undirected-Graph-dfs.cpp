// Problem: Detect Cycle in an Undirected Graph
// Difficulty: Medium
// Tags: Graph, DFS, Cycle Detection

// ✅ Approach:
// We use DFS to detect a cycle in an undirected graph.
//
// Key Idea:
// While traversing, if we reach a visited node that is NOT the parent,
// then a cycle exists.
//
// Steps:
// 1. Convert edge list to adjacency list.
// 2. Traverse each unvisited node using DFS (to handle disconnected graphs).
// 3. In DFS:
//    - Mark current node as visited.
//    - Explore all neighbors.
//    - If neighbor is already visited AND not parent → cycle found.
//    - Else continue DFS.
// 4. If any DFS call returns true → cycle exists.

class Solution {
  public:
  
    // 🔹 DFS function to detect cycle
    bool dfs(vector<vector<int>>& adj, int u, vector<bool>& visited, int parent){
        
        visited[u] = true;  // Mark current node as visited
        
        // Traverse all adjacent nodes
        for(auto& v : adj[u]){
            
            // Ignore the edge to parent node
            if(v == parent)
                continue;
                
            // 🔹 Case 1: If already visited and not parent → cycle
            if(visited[v])
                return true;
            
            // 🔹 Case 2: If not visited → explore deeper
            if(!visited[v] && dfs(adj, v, visited, u))
                return true;
        }
        
        return false;  // No cycle found in this path
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);  // Because graph is undirected
        }
        
        // Step 2: Visited array
        vector<bool> visited(V, false);
        
        // Step 3: Check all components (important for disconnected graph)
        for(int u = 0; u < V; u++){
            
            // If node not visited, start DFS
            if(!visited[u] && dfs(adj, u, visited, -1))
                return true;
        }
        
        return false;  // No cycle in any component
    }
};