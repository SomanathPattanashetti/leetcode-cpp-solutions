// Leetcode Problem: 79. Word Search
// Link: https://leetcode.com/problems/word-search/
// Difficulty: Medium
// Tags: Matrix, Backtracking, DFS

// ✅ Approach:
// We use DFS + Backtracking to check if the given word exists in the board.
// Starting from each cell that matches word[0], we explore in all 4 directions.
//
// Key steps:
// 1. Try to match characters one-by-one using DFS.
// 2. Mark the current cell as visited (using '$') to avoid revisiting.
// 3. Explore all 4 directions: up, down, left, right.
// 4. Backtrack by restoring the cell after exploring all paths.
// 5. If any path matches the full word, return true.
//
// Time Complexity: O(m * n * 4^k)
//    where k = length of the word
//
// Space Complexity: O(k) for recursion stack

class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}}; // 4 movement directions

    // DFS function to find the next character in the word
    bool findNext(vector<vector<char>>& board, string word, int idx, int i, int j) {

        // If all characters matched
        if(idx >= word.length())
            return true;

        // Boundary checks and mismatch check
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '$' || board[i][j] != word[idx])
            return false;

        char temp = board[i][j];  // Store original character
        board[i][j] = '$';        // Mark as visited

        // Explore all 4 directions
        for(auto& direction : directions){
            int new_i = i + direction[0];
            int new_j = j + direction[1];

            if(findNext(board, word, idx + 1, new_i, new_j))
                return true;
        }

        board[i][j] = temp; // Backtrack (restore original character)

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        n = board[0].size();

        // Try starting DFS from every cell
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0] && findNext(board, word, 0, i, j))
                    return true;
            }
        }

        return false; // No valid path found
    }
};
