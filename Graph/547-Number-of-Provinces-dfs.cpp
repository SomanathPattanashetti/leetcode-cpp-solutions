// Leetcode Problem: 547. Number of Provinces
// Link: https://leetcode.com/problems/number-of-provinces/
// Difficulty: Medium
// Tags: Graph, DFS, BFS, Union Find

// ✅ Approach:
// Convert the given adjacency matrix into an adjacency list.
// Each city is a node, and if isConnected[i][j] == 1, there is an edge between i and j.
//
// Use DFS to traverse the graph:
// - Maintain a visited array to track visited cities.
// - For every unvisited city, start a DFS.
// - All cities reachable from it belong to the same province.
//
// Count how many times we start a new DFS → that is the number of provinces.

class Solution {
public:

    // 🔹 DFS function to visit all connected nodes
    void dfs(unordered_map<int, vector<int>>& adj, int u, vector<int>& visited){

        // Base Case: if already visited, return
        if(visited[u])
            return;

        // Mark current node as visited
        visited[u] = true;

        // Visit all neighbors
        for(auto& v : adj[u]){
            if(!visited[v]){
                dfs(adj, v, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        unordered_map<int, vector<int>> adj;

        int m = isConnected.size();     // number of cities (rows)
        int n = isConnected[0].size();  // number of cities (cols)

        // 🔹 Step 1: Convert matrix → adjacency list
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(isConnected[i][j] == 1){

                    adj[i].push_back(j);
                    adj[j].push_back(i);  // undirected graph
                }
            }
        }

        int count = 0;                  // number of provinces
        vector<int> visited(m, false);  // visited array

        // 🔹 Step 2: Traverse all nodes
        for(int u=0; u<m; u++){

            // If city is not visited → new province
            if(!visited[u]){

                dfs(adj, u, visited);  // visit all connected cities
                count++;               // increment province count
            }
        }

        return count;
    }
};