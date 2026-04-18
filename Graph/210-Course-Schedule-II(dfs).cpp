// Leetcode Problem: 210. Course Schedule II
// Link: https://leetcode.com/problems/course-schedule-ii/
// Difficulty: Medium
// Tags: Graph, DFS, Topological Sort, Cycle Detection

// ✅ Approach:
// We use DFS + Topological Sorting to find the order of courses.
//
// Key Idea:
// - Treat courses as nodes in a graph.
// - Each prerequisite pair [a, b] means: b → a (take b before a).
//
// Steps:
// 1. Build adjacency list from prerequisites.
// 2. Perform DFS traversal for each node.
// 3. Use a recursion stack (inRecursion[]) to detect cycles.
//    - If a node is visited again in the same DFS path → cycle exists.
// 4. If cycle is detected → return empty array.
// 5. Otherwise, push nodes into stack after visiting all neighbors.
// 6. Pop stack to get topological order.

class Solution {
public:
    bool hasCycle = false;  // Flag to detect cycle in graph

    // 🔹 DFS function for traversal + cycle detection + topo sort
    void DFS(unordered_map<int, vector<int>> &adj, int u,
             vector<bool>& visited, stack<int>& st, vector<bool>& inRecursion) {

        visited[u] = true;        // Mark node as visited
        inRecursion[u] = true;    // Mark node in current recursion path

        // Traverse all neighbors
        for(int &v : adj[u]) {

            // 🔸 Cycle Detection:
            // If neighbor is already in recursion stack → cycle found
            if(inRecursion[v] == true) {
                hasCycle = true;
                return;
            }

            // If not visited, explore further
            if(!visited[v])
                DFS(adj, v, visited, st, inRecursion);
        }

        // 🔹 After visiting all neighbors:
        // Push current node into stack (for topo sort)
        st.push(u);

        // Remove from recursion stack
        inRecursion[u] = false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // 🔹 Step 1: Build adjacency list
        unordered_map<int, vector<int>> adj;

        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            // Edge: b → a (b must be done before a)
            adj[b].push_back(a);
        }

        // 🔹 Visited array
        vector<bool> visited(numCourses, false);

        // 🔹 Recursion stack tracker (for cycle detection)
        vector<bool> inRecursion(numCourses, false);

        stack<int> st;  // Stack to store topo order

        // 🔹 Step 2: Run DFS for all nodes
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i])
                DFS(adj, i, visited, st, inRecursion);
        }

        // 🔹 Step 3: If cycle exists → no valid ordering
        if(hasCycle)
            return {};

        // 🔹 Step 4: Build result from stack
        vector<int> result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};