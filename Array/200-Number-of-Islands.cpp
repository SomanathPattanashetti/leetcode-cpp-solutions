// Leetcode Problem: 200. Number of Islands
// Link: https://leetcode.com/problems/number-of-islands/
// Difficulty: Medium
// Tags: Array, DFS, BFS, Matrix

// ✅ Approach:
// We use Depth First Search (DFS) to count connected components (islands).
//
// Idea:
// 1. Traverse the entire grid.
// 2. Whenever we find a '1' (land), it means we found a new island.
// 3. Start DFS from that cell and mark all connected '1's as visited.
// 4. Increase island count.
// 5. Continue scanning the grid.
//
// We mark visited land cells with '$' to avoid revisiting.

class Solution {
public:
    
    // Directions for moving:
    // Down, Up, Right, Left
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    // DFS function to mark all connected land cells
    void dfs(vector<vector<char>>& grid, int i, int j) {
        
        // 🔹 Base Case:
        // If out of bounds OR current cell is not land ('1'), stop recursion
        if(i < 0 || i >= grid.size() || 
           j < 0 || j >= grid[0].size() || 
           grid[i][j] != '1')
            return;
        
        // Mark current cell as visited
        grid[i][j] = '$';
        
        // Explore all 4 directions
        for(pair<int, int> &p : dir) {
            int new_i = i + p.first;
            int new_j = j + p.second;
            
            dfs(grid, new_i, new_j);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        // Edge case: empty grid
        if(grid.size() == 0)
            return 0;
        
        int m = grid.size();      // Number of rows
        int n = grid[0].size();   // Number of columns
        int count = 0;            // To count islands
        
        // Traverse each cell of the grid
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                // If land is found, it's a new island
                if(grid[i][j] == '1') {
                    
                    // Mark the entire island using DFS
                    dfs(grid, i, j);
                    
                    // Increase island count
                    count++;
                }
            }
        }
        
        return count;  // Total number of islands
    }
};