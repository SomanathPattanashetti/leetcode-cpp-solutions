// Leetcode Problem: 976. Largest Perimeter Triangle
// Link: https://leetcode.com/problems/largest-perimeter-triangle/
// Difficulty: Easy
// Tags: Array, Sorting, Greedy

// ✅ Approach:
// To form a valid triangle using three sides a, b, c:
// The triangle inequality rule must hold:
//      a + b > c   (where c is the largest side)
//
// 🔹 Steps:
// 1. Sort the array in ascending order.
// 2. Traverse from the end (largest values) towards the beginning.
// 3. For every triplet (nums[i], nums[i+1], nums[i+2]):
//      - Check if nums[i] + nums[i+1] > nums[i+2]
//      - If true, this forms the largest possible perimeter (because array is sorted).
// 4. Return the perimeter of that triangle.
// 5. If no valid triangle is found, return 0.

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {

        int n = nums.size();

        // Sort the array to easily check triangle condition
        sort(nums.begin(), nums.end());

        // Start checking from the largest possible triplet
        for (int i = n - 3; i >= 0; i--) {

            // Triangle condition:
            // Sum of two smaller sides must be greater than the largest side
            if (nums[i] + nums[i + 1] > nums[i + 2]) {

                // Valid triangle found with maximum possible perimeter
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }

        // No valid triangle can be formed
        return 0;
    }
};
