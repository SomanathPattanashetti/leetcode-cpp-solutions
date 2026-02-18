// Leetcode Problem: 1877. Minimize Maximum Pair Sum in Array
// Link: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
// Difficulty: Medium
// Tags: Array, Two Pointers, Greedy, Sorting

// ✅ Approach:
// To minimize the maximum pair sum, we should always pair:
//   smallest element  ↔  largest element
//
// Why?
// If large numbers pair together, the sum becomes very big.
// Instead, balance big with small → keeps maximum sum minimum.
//
// Steps:
// 1. Sort the array
// 2. Use two pointers:
//      i → start (smallest)
//      j → end (largest)
// 3. Form pairs and track the maximum pair sum
// 4. Return the largest sum among all pairs (which is minimized globally)

class Solution {
public:
    int minPairSum(vector<int>& nums) {

        // Step 1: Sort array so smallest and largest are at ends
        sort(begin(nums), end(nums));

        int i = 0;
        int j = nums.size() - 1;
        int res = 0; // Stores minimized maximum pair sum

        // Step 2: Pair smallest with largest
        while(i < j){

            // Current pair sum
            int pairSum = nums[i] + nums[j];

            // Track the maximum pair sum among all pairs
            res = max(res, pairSum);

            // Move inward
            i++;
            j--;
        }

        // Step 3: Final minimized maximum pair sum
        return res;
    }
};
