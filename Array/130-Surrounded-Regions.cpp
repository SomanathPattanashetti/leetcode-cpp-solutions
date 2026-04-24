// Leetcode Problem: 130. Surrounded Regions
// Link: https://leetcode.com/problems/surrounded-regions/
// Difficulty: Medium
// Tags: Graph, DFS, BFS, Matrix

// ✅ Approach:
// The goal is to capture all regions surrounded by 'X'.
// A region is captured by flipping all 'O' → 'X' that are NOT connected to boundary.
//
// 🔥 Key Idea:
// - Any 'O' connected to the boundary cannot be flipped.
// - So instead of finding surrounded regions directly,
//   we mark all safe 'O's (connected to boundary).
//
// ✅ Steps:
// 1. Traverse boundary (first row, last row, first column, last column)
// 2. If a boundary cell is 'O', run DFS and mark all connected 'O's as visited (safe)
// 3. Traverse the entire board:
//    - If cell is 'O' and NOT visited → flip to 'X'
//    - Else keep it as 'O'

// ✅ Time Complexity: O(m * n)
// Each cell is visited at most once

// ✅ Space Complexity: O(m * n)
// Due to visited array + recursion stack

class Solution {
public:

    int m, n;

    // Directions for up, down, left, right
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    // DFS to mark safe 'O's (connected to boundary)
    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited){

        visited[i][j] = true;

        for(auto& d : directions){
            int ni = i + d[0];
            int nj = j + d[1];

            // Explore only valid, unvisited 'O' cells
            if(ni>=0 && ni<m && nj>=0 && nj<n &&
               !visited[ni][nj] && board[ni][nj]=='O'){
                dfs(board, ni, nj, visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        m = board.size();
        n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n,false));

        // 🔹 Step 1: Check first & last rows
        for(int i=0; i<n; i++){
            if(board[0][i]=='O' && !visited[0][i])
                dfs(board, 0, i, visited);

            if(board[m-1][i]=='O' && !visited[m-1][i])
                dfs(board, m-1, i, visited);
        }

        // 🔹 Step 2: Check first & last columns
        for(int j=0; j<m; j++){
            if(board[j][0]=='O' && !visited[j][0])
                dfs(board, j, 0, visited);

            if(board[j][n-1]=='O' && !visited[j][n-1])
                dfs(board, j, n-1, visited);
        }

        // 🔹 Step 3: Flip surrounded regions
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !visited[i][j])
                    board[i][j]='X';
            }
        }
    }
};