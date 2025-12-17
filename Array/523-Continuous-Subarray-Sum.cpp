// Leetcode Problem: 523. Continuous Subarray Sum
// Link: https://leetcode.com/problems/continuous-subarray-sum/
// Difficulty: Medium
// Tags: Array, Hash Table, Prefix Sum, Modulo

// ✅ Approach:
// We use the concept of Prefix Sum + Modulo.
// If two prefix sums have the same remainder when divided by k,
// then the subarray between them has a sum divisible by k.
//
// Let:
//   prefixSum[i] % k == prefixSum[j] % k  (i < j)
// Then:
//   (prefixSum[j] - prefixSum[i]) % k == 0
//
// To ensure the subarray length is at least 2,
// we check that the index difference is >= 2.
//
// We store the FIRST occurrence of each remainder in a hash map.

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;  
        // Stores: remainder -> earliest index where it appeared

        int n = nums.size();
        int sum = 0;  // Prefix sum

        // Base case:
        // Remainder 0 at index -1 helps detect subarrays
        // starting from index 0
        mp[0] = -1;

        for (int i = 0; i < n; i++) {

            // Add current element to prefix sum
            sum += nums[i];

            // Compute remainder of prefix sum
            int rem = sum % k;

            // If this remainder was seen before
            if (mp.find(rem) != mp.end()) {

                // Check if subarray length is at least 2
                if (i - mp[rem] >= 2)
                    return true;
            }
            else {
                // Store first occurrence of this remainder
                mp[rem] = i;
            }
        }

        // No valid subarray found
        return false;
    }
};
