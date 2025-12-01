// Problem: Rat in a Maze (GFG / Common Backtracking Problem)
// Difficulty: Medium
// Tags: Backtracking, Matrix, DFS, Recursion
//
// ✅ Approach:
// We use **Backtracking + DFS** to explore all possible paths from (0,0) to (n-1,m-1).
//
// Rules:
// - You can only move on cells with value 1 (open path).
// - Possible moves: D (Down), L (Left), R (Right), U (Up)
// - We mark the current cell as visited before exploring neighbors
//   and unmark it while backtracking.
//
// Steps:
// 1. Start from (0,0). If it's blocked, no paths exist.
// 2. Try all four directions in the order D, L, R, U.
// 3. Whenever we reach the bottom-right corner, store the current path string.
// 4. Restore the visited cell while backtracking.
// 
// This ensures all valid paths are collected.

class Solution {
public:
    
    vector<string> res;  // Stores all valid paths
    int n, m;            // Maze dimensions

    // DFS + Backtracking function to explore paths
    void solve(vector<vector<int>>& maze, int i, int j, string& pathh) {

        // ❌ Boundary Check OR Blocked Cell
        if(i < 0 || i >= n || j < 0 || j >= m || maze[i][j] != 1)
            return;

        // 🎯 Reached destination (bottom-right cell)
        if(i == n - 1 && j == m - 1) {
            res.push_back(pathh);
            return;
        }

        // Mark the cell as visited
        maze[i][j] = 0;

        // 🔽 Move Down
        pathh.push_back('D');
        solve(maze, i + 1, j, pathh);
        pathh.pop_back();  // Backtrack

        // ◀️ Move Left
        pathh.push_back('L');
        solve(maze, i, j - 1, pathh);
        pathh.pop_back();

        // ▶️ Move Right
        pathh.push_back('R');
        solve(maze, i, j + 1, pathh);
        pathh.pop_back();

        // 🔼 Move Up
        pathh.push_back('U');
        solve(maze, i - 1, j, pathh);
        pathh.pop_back();

        // Unmark the cell (backtracking)
        maze[i][j] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {

        n = maze.size();
        m = maze[0].size();

        string pathh = "";

        solve(maze, 0, 0, pathh);  // Start from top-left cell

        return res;  // Contains all valid paths
    }
};
