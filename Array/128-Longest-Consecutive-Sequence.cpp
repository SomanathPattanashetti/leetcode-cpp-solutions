// Leetcode Problem: 128. Longest Consecutive Sequence
// Link: https://leetcode.com/problems/longest-consecutive-sequence/
// Difficulty: Medium
// Tags: Array, Hash Table

// ✅ Approach:
// Use a Hash Map to track all numbers and whether they are already visited.
//
// Steps:
// 1. Insert all numbers into a hash map with value = false (not visited).
// 2. For each number:
//    - Expand forward (num + 1, num + 2, ...) while numbers exist and are unvisited.
//    - Expand backward (num - 1, num - 2, ...) while numbers exist and are unvisited.
// 3. Mark visited numbers during expansion to avoid reprocessing.
// 4. Track the maximum length found.
//
// This ensures each number is processed only once → O(n) time complexity.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int, bool> mp;  // Stores number -> visited status
        int longest_len = 0;          // Stores maximum consecutive length

        // Insert all numbers into the map and mark them as unvisited
        for(auto& num : nums)
            mp[num] = false;
        
        // Try to build consecutive sequences from each number
        for(auto& num : nums){

            int curr_len = 1;        // Length of current sequence
            int next_num = num + 1;

            // 🔹 Expand forward
            while(mp.find(next_num) != mp.end() && mp[next_num] == false){
                curr_len++;
                mp[next_num] = true;   // Mark as visited
                next_num++;
            }

            int prev_num = num - 1;

            // 🔹 Expand backward
            while(mp.find(prev_num) != mp.end() && mp[prev_num] == false){
                curr_len++;
                mp[prev_num] = true;   // Mark as visited
                prev_num--;
            }

            // Update the longest sequence length
            longest_len = max(longest_len, curr_len);
        }

        return longest_len;
    }
};
