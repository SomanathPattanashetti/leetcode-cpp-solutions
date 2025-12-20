// Leetcode Problem: 31. Next Permutation
// Link: https://leetcode.com/problems/next-permutation/
// Difficulty: Medium
// Tags: Array, Two Pointers

// ✅ Approach:
// The goal is to rearrange numbers into the next lexicographically greater permutation.
//
// Steps:
// 1. Traverse from right to left and find the first index (pivot)
//    such that nums[i] < nums[i + 1].
//    This identifies where the order stops increasing.
//
// 2. If no pivot is found, the array is in descending order.
//    Reverse the entire array to get the smallest permutation.
//
// 3. Otherwise, find the smallest element greater than nums[pivot]
//    from the right side and swap them.
//
// 4. Reverse the subarray to the right of pivot to get the next smallest order.

class Solution {
public:

    // 🔹 Helper function to reverse a subarray
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }

    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int pivot = -1;

        // Step 1: Find the pivot index
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2: If no pivot found, reverse entire array
        if (pivot == -1) {
            reverse(nums, 0, n - 1);
            return;
        }

        // Step 3: Find element just greater than pivot and swap
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Step 4: Reverse the suffix after pivot
        reverse(nums, pivot + 1, n - 1);
    }
};
