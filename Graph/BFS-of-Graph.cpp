// Leetcode / GFG Problem: BFS of Graph
// Difficulty: Easy
// Tags: Graph, BFS, Queue

// ✅ Approach:
// We use Breadth First Search (BFS) to traverse the graph level by level.
//
// BFS starts from node 0 and visits all its adjacent unvisited nodes first.
// For this, we use a queue data structure.
//
// Steps:
// 1. Push the starting node into the queue
// 2. Mark it as visited
// 3. While queue is not empty:
//      - Take the front node
//      - Visit all its unvisited neighbours
//      - Mark them visited and push them into queue
//
// This ensures nodes are visited in BFS order.

class Solution {
  public:
  
    // Function to perform BFS traversal starting from node 'u'
    void solve(std::unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, vector<int>& result){
        
        std::queue<int> que;   // Queue for BFS traversal
        
        // Start BFS from node 'u'
        que.push(u);
        visited[u] = true;
        result.push_back(u);
        
        // Continue until queue becomes empty
        while(!que.empty()){
            
            int u = que.front();   // Get front node
            que.pop();             // Remove it from queue
            
            // Traverse all neighbours of current node
            for(auto& v : adj[u]){
                if(!visited[v]){
                    visited[v] = true;   // Mark neighbour as visited
                    que.push(v);         // Push neighbour into queue
                    result.push_back(v); // Store BFS traversal order
                }
            }
        }
    }
    
    
    vector<int> bfs(vector<vector<int>> &list) {
        
        // Adjacency list stored in unordered_map
        std::unordered_map<int, vector<int>> adj;
        
        int v = list.size();   // Number of vertices
        
        // Convert given vector list into adjacency map
        for(int u = 0; u < v; u++){
            for(auto& v : list[u]){
                adj[u].push_back(v);
            }
        }
        
        vector<bool> visited(v + 1, false); // Track visited nodes
        vector<int> result;                 // Store BFS traversal
        
        // Start BFS from node 0
        solve(adj, 0, visited, result);
        
        return result;   // Return BFS order
    }
};