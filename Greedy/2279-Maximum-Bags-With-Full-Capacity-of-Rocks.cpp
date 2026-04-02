// Leetcode Problem: 2279. Maximum Bags With Full Capacity of Rocks
// Link: https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
// Difficulty: Medium
// Tags: Array, Greedy, Sorting

// ✅ Approach:
// First, calculate how many more rocks each bag needs to become full.
// Store these required values in a separate array.
//
// Then, sort this array so we can fill the bags that need the fewest rocks first.
// This is a Greedy approach because filling smaller gaps first helps maximize
// the total number of completely filled bags.
//
// Traverse the sorted array:
// - If we have enough additional rocks, fill that bag
// - Reduce additionalRocks accordingly
// - Increase the count of full bags
//
// Stop when we don’t have enough rocks to fill the next bag.

int n = capacity.size();   // Total number of bags
int count = 0;             // Stores number of bags that can be made full
vector<int> vec(n);        // Stores rocks needed for each bag to become full

// Step 1: Find how many rocks each bag still needs
for(int i = 0; i < n; i++) {
    vec[i] = capacity[i] - rocks[i];
}

// Step 2: Sort the required rocks in ascending order
// So we can fill the bags needing the least rocks first
sort(begin(vec), end(vec));

// Step 3: Try filling bags one by one greedily
for(int i = 0; i < n; i++) {

    // If we have enough rocks to fill this bag
    if(additionalRocks >= vec[i]) {
        additionalRocks -= vec[i];  // Use the required rocks
        count++;                    // One more bag is now full
    } else {
        // Not enough rocks to fill the current bag
        break;
    }
}

// Step 4: Return maximum number of full bags
return count;