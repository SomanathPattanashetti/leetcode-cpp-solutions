// Leetcode Problem: 785. Is Graph Bipartite?
// Link: https://leetcode.com/problems/is-graph-bipartite/
// Difficulty: Medium
// Tags: Graph, BFS, DFS, Coloring

// ✅ Approach:
// A graph is bipartite if we can divide nodes into 2 sets such that
// no two adjacent nodes have the same color.
//
// We use BFS traversal + Coloring technique:
// - Assign a color (0 or 1) to the starting node.
// - For every adjacent node:
//      • If not colored → assign opposite color and push to queue
//      • If already colored and same as current → NOT bipartite
//
// We repeat this for all components (in case graph is disconnected).

class Solution {
public:

    // 🔹 BFS function to check bipartite for a component
    bool checkisBipartiteBFS(vector<vector<int>>& adj, int curr_node, vector<int>& color, int curr_color){

        queue<int> que;

        // Start BFS and assign initial color
        que.push(curr_node);
        color[curr_node] = curr_color;

        while(!que.empty()){

            int curr_node = que.front();
            que.pop();

            // Traverse all adjacent nodes
            for(auto& v : adj[curr_node]){

                // ❌ If same color → not bipartite
                if(color[v] == color[curr_node])
                    return false;

                // 🔹 If not colored → assign opposite color
                else if(color[v] == -1){
                    int new_color = color[curr_node] == 1 ? 0 : 1;
                    color[v] = new_color;
                    que.push(v);
                }
            }
        }

        // ✅ No conflict found → bipartite
        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        
        int V = adj.size();

        // -1 means not colored
        vector<int> color(V, -1);

        // Handle disconnected components
        for(int u = 0; u < V; u++){

            // If node not visited, start BFS
            if(color[u] == -1){
                if(checkisBipartiteBFS(adj, u, color, 1) == false)
                    return false;
            }
        }

        // ✅ All components are bipartite
        return true;
    }
};