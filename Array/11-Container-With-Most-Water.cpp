// Leetcode Problem: 11. Container With Most Water
// Link: https://leetcode.com/problems/container-with-most-water/
// Difficulty: Medium
// Tags: Array, Two Pointers, Greedy

// ✅ Approach:
// We use the Two Pointer technique.
//
// Start with two pointers:
//  left at beginning (i)
//  right at end (j)
//
// The water stored between two lines is:
//      area = min(height[i], height[j]) * (j - i)
//
// Key Greedy Observation:
// The shorter line limits the water height.
// So moving the taller line will NEVER increase area.
// We must move the shorter line hoping to find a taller one.
//
// Steps:
// 1. Calculate current area
// 2. Update max_area
// 3. Move pointer of smaller height inward
//
// Repeat until pointers meet.

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i = 0;                        // Left pointer
        int j = height.size() - 1;        // Right pointer
        int max_area = 0;                 // Stores maximum area

        while(i < j){

            int h = min(height[i], height[j]);  // Water height limited by shorter line
            int w = j - i;                      // Width between lines

            max_area = max(max_area, (h * w));  // Update maximum area

            // Move the smaller height pointer
            if(height[i] < height[j]){
                i++;    // Try to find taller left line
            }else{
                j--;    // Try to find taller right line
            }
        }

        return max_area;
    }
};