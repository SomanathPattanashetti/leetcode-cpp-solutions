// Leetcode Problem: 75. Sort Colors
// Link: https://leetcode.com/problems/sort-colors/
// Difficulty: Medium
// Tags: Array, Two Pointers, Dutch National Flag Algorithm

// ✅ Approach:
// We solve this using the Dutch National Flag Algorithm.
// The array contains only 0s, 1s and 2s.
//
// Idea:
// 0 -> move to beginning
// 1 -> stay in middle
// 2 -> move to end
//
// We maintain 3 pointers:
// i -> next position for 0
// j -> current element (scanner)
// k -> next position for 2
//
// Rules while traversing:
// If nums[j] == 0 → swap with i, move i & j forward
// If nums[j] == 1 → already in correct region → just move j
// If nums[j] == 2 → swap with k, move k backward (do NOT move j yet)

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();

        int i = 0;        // left boundary for 0s
        int j = 0;        // current index
        int k = n - 1;    // right boundary for 2s

        // Traverse until current pointer crosses right boundary
        while (j <= k) {

            // 🔹 Case 1: Element is 2 → move to end
            if (nums[j] == 2) {
                swap(nums[j], nums[k]);
                k--;               // shrink 2s region
                // j NOT incremented because swapped element needs checking
            }

            // 🔹 Case 2: Element is 0 → move to front
            else if (nums[j] == 0) {
                swap(nums[j], nums[i]);
                i++;               // expand 0s region
                j++;               // move to next element
            }

            // 🔹 Case 3: Element is 1 → already correct
            else {
                j++;               // just move ahead
            }
        }
    }
};