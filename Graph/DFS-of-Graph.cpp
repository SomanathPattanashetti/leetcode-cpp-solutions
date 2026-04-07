// GFG Problem: DFS of Graph
// Link: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// Difficulty: Easy
// Tags: Graph, DFS, Recursion

// ✅ Approach:
// Use Depth First Search (DFS) to traverse the graph.
// Start from node 0 and visit all connected nodes recursively.
//
// DFS works by:
// 1. Marking the current node as visited
// 2. Storing it in the result
// 3. Visiting all its unvisited adjacent nodes recursively
//
// This ensures every reachable node is visited exactly once.

class Solution {
  public:
    
    int v;  // Stores total number of vertices

    // Recursive DFS function
    void solve(vector<vector<int>>& adj, int u, vector<int>& visited, vector<int>& result) {
        
        // Base Case:
        // If the node is already visited, return
        if(visited[u])
            return;
            
        // Mark current node as visited
        visited[u] = true;
        
        // Store current node in DFS traversal result
        result.push_back(u);
        
        // Visit all adjacent nodes of current node
        for(auto& v : adj[u]) {
            if(!visited[v])
                solve(adj, v, visited, result);
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        
        // Total number of vertices in graph
        v = adj.size();
        
        // Visited array to track visited nodes
        vector<int> visited(v, 0);
        
        // Stores final DFS traversal
        vector<int> result;
        
        // Start DFS from node 0
        solve(adj, 0, visited, result);
        
        // Return DFS traversal
        return result;
    }
};