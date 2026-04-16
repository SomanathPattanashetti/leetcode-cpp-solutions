// Leetcode Problem: 210. Course Schedule II
// Link: https://leetcode.com/problems/course-schedule-ii/
// Difficulty: Medium
// Tags: Graph, BFS, Topological Sort

// ✅ Approach:
// We use Kahn’s Algorithm (BFS-based Topological Sort) to find a valid course order.
//
// Steps:
// 1. Build the graph using adjacency list:
//    If course B must be done before A → edge: B → A
//
// 2. Maintain an inDegree array:
//    inDegree[i] = number of prerequisites for course i
//
// 3. Push all nodes with inDegree = 0 into queue
//    (these can be taken first)
//
// 4. Perform BFS:
//    - Pop node from queue
//    - Add it to result
//    - Reduce inDegree of its neighbors
//    - If any neighbor becomes 0 → push into queue
//
// 5. If we process all nodes → valid order exists
//    Else → cycle exists → return empty array

class Solution {
public:

    // Function to perform Topological Sort using BFS
    vector<int> topologicalSort(unordered_map<int, vector<int>>& adj, int n, vector<int>& inDegree, vector<int>& result){
        
        queue<int> que;
        int count = 0;  // To track processed nodes

        // Step 1: Push all nodes with 0 inDegree
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                result.push_back(i);
                que.push(i);
                count++;
            }
        }

        // Step 2: BFS traversal
        while(!que.empty()){

            int u = que.front();
            que.pop();

            // Process all neighbors
            for(auto& v : adj[u]){

                inDegree[v]--;

                // If inDegree becomes 0, push into queue
                if(inDegree[v] == 0){
                    que.push(v);
                    result.push_back(v);
                    count++;
                }
            }
        }

        // Step 3: Check for cycle
        // If count != n → cycle exists → return empty
        return count == n ? result : vector<int>{};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> adj;  // Adjacency list
        vector<int> inDegree(numCourses, 0);  // In-degree array
        vector<int> result;                  // Stores final order

        // Step 1: Build graph
        for(auto& prerequisite : prerequisites){
            int a = prerequisite[0];  // Course
            int b = prerequisite[1];  // Prerequisite

            adj[b].push_back(a);  // Edge: b → a
            inDegree[a]++;        // Increase inDegree of a
        }

        // Step 2: Perform Topological Sort
        return topologicalSort(adj, numCourses, inDegree, result);
    }
};