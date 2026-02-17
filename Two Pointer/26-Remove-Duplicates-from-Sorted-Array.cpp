// Leetcode Problem: 26. Remove Duplicates from Sorted Array
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Difficulty: Easy
// Tags: Array, Two Pointers

// ✅ Approach:
// The array is already sorted.
// So duplicates will always be next to each other.
//
// We use the Two Pointer Technique:
//  - Pointer i → scans the array
//  - Pointer j → keeps position of last unique element
//
// Steps:
// 1. Start j at index 0 (first element is always unique)
// 2. Traverse the array using i
// 3. Whenever nums[i] != nums[j]
//      → found a new unique element
//      → move j forward
//      → place nums[i] at nums[j]
//
// Finally, first (j+1) elements contain all unique values.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int j(0);                // Pointer for last unique element
        int n(nums.size());      // Size of array

        // Traverse array
        for(int i = 0; i < n; i++) {

            // If a new unique element is found
            if(nums[i] != nums[j]) {
                j++;            // Move unique pointer forward
                nums[j] = nums[i]; // Place unique element at correct position
            }
        }

        // Number of unique elements
        return j + 1;
    }
};
