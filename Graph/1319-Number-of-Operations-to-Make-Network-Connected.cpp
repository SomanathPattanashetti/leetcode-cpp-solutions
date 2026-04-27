// Leetcode Problem: 1319. Number of Operations to Make Network Connected
// Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Difficulty: Medium
// Tags: Graph, DFS, BFS, Union-Find (DSU)

// ✅ Approach:
// We use Disjoint Set Union (Union-Find) to track connected components.
//
// Key Idea:
// - There are n computers (nodes).
// - connections represent cables (edges).
// - To connect n nodes, we need at least (n - 1) edges.
//   If not, it's impossible → return -1.
//
// Steps:
// 1. Initialize DSU (parent + rank).
// 2. Treat each node as its own component initially.
// 3. For each connection:
//    - If nodes belong to different components → union them
//    - Reduce number of components
// 4. Final answer = (components - 1)
//   (because to connect k components, we need k-1 operations)

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    // 🔹 Find function with Path Compression
    // Finds the ultimate parent (leader) of a node
    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]); // Path Compression
    }

    // 🔹 Union by Rank
    // Connects two components efficiently
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        // If both belong to same component, no need to merge
        if (x_parent == y_parent)
            return;

        // Attach smaller rank tree under larger rank tree
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } 
        else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } 
        else {
            // If ranks are same, choose any and increase rank
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        // ❌ Not enough edges to connect all nodes
        if (connections.size() < n - 1)
            return -1;

        // 🔹 Initialize DSU
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int components = n; // Initially, all nodes are separate

        // 🔹 Process all connections
        for (auto& vec : connections) {
            if (find(vec[0]) != find(vec[1])) {
                components--;              // Components reduced
                Union(vec[0], vec[1]);     // Merge them
            }
        }

        // 🔹 To connect remaining components
        // We need (components - 1) operations
        return components - 1;
    }
};