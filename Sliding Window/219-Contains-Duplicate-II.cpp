// Leetcode Problem: 219. Contains Duplicate II
// Link: https://leetcode.com/problems/contains-duplicate-ii/
// Difficulty: Easy
// Tags: Array, Hash Table, Sliding Window

// ✅ Approach:
// Use a Sliding Window technique with a Hash Set.
// The window size is maintained such that the distance
// between indices is at most `k`.
//
// We move a window using two pointers (i and j):
// - `j` expands the window by adding elements
// - `i` shrinks the window when the distance exceeds `k`
//
// At each step:
// - If the current element already exists in the set,
//   it means a duplicate is found within distance `k` → return true.
// - Otherwise, insert the element into the set.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int n(nums.size());
        int i(0), j(0);  // Sliding window pointers

        unordered_set<int> st;  // Stores elements in current window

        while(j < n){

            // 🔹 If window size exceeds k, remove the left element
            if(abs(i - j) > k){
                st.erase(nums[i]);
                i++;
            }

            // 🔹 If current element already exists in the set
            //    then duplicate is found within range k
            if(st.find(nums[j]) != st.end())
                return true;

            // 🔹 Insert current element into the window
            st.insert(nums[j]);
            j++;
        }

        // No duplicates found within distance k
        return false;
    }
};
