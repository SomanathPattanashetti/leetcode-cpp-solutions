// Leetcode Problem: 207. Course Schedule
// Link: https://leetcode.com/problems/course-schedule/
// Difficulty: Medium
// Tags: Graph, DFS, Cycle Detection, Topological Sort

// ✅ Approach:
// This problem is about detecting a cycle in a directed graph.
//
// Each course is a node, and prerequisites form directed edges:
// If course A depends on B → edge: B → A
//
// If there is a cycle in the graph, it means we cannot complete all courses.
//
// We use DFS + Recursion Stack (inRecursion array):
// 1. visited[] → to track visited nodes
// 2. inRecursion[] → to track nodes in current DFS path
//
// 🔁 Cycle Detection Logic:
// - If we visit a node that is already in the recursion stack → cycle exists
// - If no cycle is found → we can finish all courses

class Solution {
public:

    // DFS function to detect cycle in directed graph
    bool isCycleDetectDFS(unordered_map<int, vector<int>>& adj, int u, 
                         vector<bool>& visited, vector<bool>& inRecursion){

        // Mark current node as visited and part of recursion stack
        visited[u] = true;
        inRecursion[u] = true;

        // Traverse all neighbors
        for(auto& v : adj[u]){

            // 🔹 Case 1: If neighbor not visited, recursively check
            if(!visited[v] && isCycleDetectDFS(adj, v, visited, inRecursion))
                return true;

            // 🔹 Case 2: If neighbor is already in recursion stack → cycle
            else if(inRecursion[v])
                return true;
        }
        
        // Remove node from recursion stack (backtracking)
        inRecursion[u] = false;

        return false; // No cycle found from this node
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Adjacency list to represent graph
        unordered_map<int, vector<int>> adj;

        // Build graph
        for(auto& prerequisite : prerequisites){

            int a = prerequisite[0]; // course to take
            int b = prerequisite[1]; // prerequisite

            // Edge: b → a
            adj[b].push_back(a);
        }   

        // Track visited nodes
        vector<bool> visited(numCourses, false);

        // Track recursion stack
        vector<bool> inRecursion(numCourses, false);

        // Check for cycle in all components
        for(int u = 0; u < numCourses; u++){

            if(!visited[u] && isCycleDetectDFS(adj, u, visited, inRecursion))
                return false; // cycle detected → cannot finish
        }

        return true; // no cycle → can finish all courses
    }
};