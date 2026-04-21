// Leetcode Problem: 733. Flood Fill
// Link: https://leetcode.com/problems/flood-fill/
// Difficulty: Easy
// Tags: DFS, BFS, Matrix

// ✅ Approach:
// We use DFS (Depth First Search) to fill all connected pixels
// having the same original color as the starting pixel.
//
// Steps:
// 1. Store the original color at (sr, sc).
// 2. If the original color is already equal to the new color,
//    no need to process further (avoid infinite recursion).
// 3. Start DFS from (sr, sc):
//      - If the current cell is out of bounds OR
//        does not match the original color → stop.
//      - Otherwise, change its color to the new color.
//      - Recursively apply DFS in 4 directions (up, down, left, right).
//
// This ensures all connected components of the same color are filled.

class Solution {
public:

    int m, n; // Dimensions of the image (rows, cols)

    // 🔹 DFS function to perform flood fill
    void dfs(vector<vector<int>>& image, int i, int j, int color, int org_color){

        // Base Case:
        // If out of bounds OR current cell is not of original color → stop
        if(i < 0 || i >= m || j < 0 || j >= n || image[i][j] != org_color)
            return;

        // Change the color of current cell
        image[i][j] = color;

        // Explore all 4 directions
        dfs(image, i+1, j, color, org_color); // Down
        dfs(image, i-1, j, color, org_color); // Up
        dfs(image, i, j+1, color, org_color); // Right
        dfs(image, i, j-1, color, org_color); // Left
    }   

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        // Initialize dimensions
        m = image.size();
        n = image[0].size();

        // Get original color of starting pixel
        int org_color = image[sr][sc];

        // Edge Case:
        // If original color is same as new color → no changes needed
        if (org_color == color) return image;
        
        // Start DFS from starting pixel
        dfs(image, sr, sc, color, org_color);

        return image;
    }
};