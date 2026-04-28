// Leetcode Problem: 841. Keys and Rooms
// Link: https://leetcode.com/problems/keys-and-rooms/
// Difficulty: Medium
// Tags: Graph, DFS, BFS

// ✅ Approach:
// This problem can be treated as a graph traversal problem.
// Each room is a node, and keys inside the room act as edges to other rooms.
//
// We start from room 0 (initially unlocked).
// Use DFS to visit all reachable rooms using the available keys.
//
// Steps:
// 1. Maintain a visited array to track visited rooms.
// 2. Start DFS from room 0.
// 3. For every key in the current room, visit the corresponding room if not visited.
// 4. After DFS, check if all rooms are visited.
//    - If yes → return true
//    - Otherwise → return false

class Solution {
public:

    // 🔹 DFS function to traverse rooms
    void dfs(vector<vector<int>>& rooms, int src, vector<bool>& visited){
        
        // Mark current room as visited
        visited[src] = true;

        // Explore all rooms for which we have keys
        for(auto& node : rooms[src]){
            if(!visited[node])
                dfs(rooms, node, visited);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int V = rooms.size();

        // Visited array to track visited rooms
        vector<bool> visited(V, false);
        
        // Start DFS from room 0
        dfs(rooms, 0, visited);

        // Check if all rooms are visited
        for(auto x : visited){
            if(x == false)
                return false;
        }

        // All rooms are reachable
        return true;
    }
};