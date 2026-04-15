// Leetcode Problem: 207. Course Schedule
// Link: https://leetcode.com/problems/course-schedule/
// Difficulty: Medium
// Tags: Graph, BFS, Topological Sort, Kahn's Algorithm

// ✅ Approach:
// We use Kahn’s Algorithm (BFS-based Topological Sort) to detect a cycle.
//
// Idea:
// - Each course is a node in a graph.
// - A prerequisite [a, b] means: b → a (you must complete b before a).
//
// Steps:
// 1. Build an adjacency list from prerequisites.
// 2. Maintain an inDegree array:
//    - inDegree[i] = number of prerequisites for course i.
// 3. Push all nodes with inDegree = 0 into a queue (no dependencies).
// 4. Perform BFS:
//    - Remove node from queue.
//    - Reduce inDegree of its neighbors.
//    - If any neighbor's inDegree becomes 0, push it into queue.
// 5. Count how many nodes we process.
//
// 👉 If count == total courses → No cycle → Possible to finish courses
// 👉 Else → Cycle exists → Not possible

class Solution {
public:

    // Function to check if graph has a cycle using BFS (Kahn's Algorithm)
    bool cycleCheck(unordered_map<int, vector<int>>& adj, int n, vector<int>& inDegree){

        queue<int> que;
        int count = 0;  // Number of nodes processed

        // Step 1: Push all nodes with inDegree 0
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                count++;
                que.push(i);
            }
        }

        // Step 2: BFS traversal
        while(!que.empty()){

            int u = que.front();
            que.pop();

            // Traverse neighbors
            for(auto& v : adj[u]){

                inDegree[v]--;  // Reduce dependency

                // If no more dependencies, push to queue
                if(inDegree[v] == 0){
                    count++;
                    que.push(v);
                }
            }
        }

        // Step 3: If all nodes processed → No cycle
        return count == n;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> adj;  // Adjacency list
        
        vector<int> inDegree(numCourses, 0);  // In-degree array

        // Step 1: Build graph
        for(auto& prerequisite : prerequisites){
            int a = prerequisite[0];
            int b = prerequisite[1];

            adj[b].push_back(a);  // Edge: b → a
            inDegree[a]++;        // a has one more dependency
        }

        // Step 2: Check for cycle
        return cycleCheck(adj, numCourses, inDegree);
    }
};