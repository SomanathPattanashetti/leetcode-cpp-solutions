// Leetcode Problem: 785. Is Graph Bipartite?
// Link: https://leetcode.com/problems/is-graph-bipartite/
// Difficulty: Medium
// Tags: Graph, DFS, BFS, Coloring

// ✅ Approach:
// A graph is bipartite if we can divide nodes into 2 groups
// such that no two adjacent nodes have the same color.
//
// We use DFS + Coloring technique:
// - Assign a color (0 or 1) to each node
// - For every adjacent node, assign the opposite color
// - If we ever find a neighbor with the same color → Not bipartite
//
// Also, since the graph may be disconnected,
// we run DFS for every unvisited node.

class Solution {
public:

    // 🔹 DFS function to check bipartiteness
    bool checkisBipartiteDFS(vector<vector<int>>& adj, int curr_node, vector<int>& coloured, int curr_colour){

        // Assign color to current node
        coloured[curr_node] = curr_colour;

        // Traverse all neighbors
        for(auto& v : adj[curr_node]){

            // ❌ If neighbor has same color → Not bipartite
            if(coloured[v] == coloured[curr_node])
                return false;

            // 🔹 If neighbor is not colored → DFS on it
            if(coloured[v] == -1){

                // Assign opposite color
                int new_colour = curr_colour == 1 ? 0 : 1;

                // If any DFS call fails → return false
                if(checkisBipartiteDFS(adj, v, coloured, new_colour) == false)
                    return false;
            }
        }

        // ✅ If no conflicts found
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& adj) {

        int V = adj.size();
        
        // Initialize all nodes as uncolored (-1)
        vector<int> coloured(V, -1);

        // 1 = Red, 0 = Blue

        // 🔹 Handle disconnected graph
        for(int u = 0; u < V; u++){

            // If node is not visited, start DFS
            if(coloured[u] == -1){

                // If DFS fails → Graph is not bipartite
                if(checkisBipartiteDFS(adj, u, coloured, 1) == false)
                    return false;
            }
        }

        // ✅ All components are bipartite
        return true;
    }
};