// Leetcode Problem: 547. Number of Provinces
// Link: https://leetcode.com/problems/number-of-provinces/
// Difficulty: Medium
// Tags: Graph, BFS, DFS, Connected Components

// ✅ Approach:
// Convert the given adjacency matrix into an adjacency list for easy traversal.
// Then, we count the number of connected components using BFS.
//
// 🔹 Key Idea:
// Each province is a connected component in the graph.
// So, we traverse all nodes and whenever we find an unvisited node,
// we start BFS from it and mark all reachable nodes as visited.
// Each BFS call represents one province.

class Solution {
public:

    // BFS function to traverse all nodes in the current component
    void bfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited){

        queue<int> que;
        que.push(u);
        visited[u] = true;

        while(!que.empty()){

            int u = que.front();
            que.pop();

            for(auto& v : adj[u]){

                // If neighbor is not visited, mark and push into queue
                if(!visited[v]){
                    visited[v] = true;
                    que.push(v);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        
        unordered_map<int, vector<int>> adj;

        // 🔹 Step 1: Convert adjacency matrix to adjacency list
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i); // undirected graph
                }
            }
        }

        vector<bool> visited(n, false);
        int count = 0;

        // 🔹 Step 2: Traverse all nodes
        for(int u=0; u<n; u++){

            // If node is not visited, it means a new province
            if(!visited[u]){
                bfs(adj, u, visited);
                count++;  // increment province count
            }
        }

        return count;
    }
};