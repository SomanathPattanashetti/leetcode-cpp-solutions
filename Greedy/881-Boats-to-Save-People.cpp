// Leetcode Problem: 881. Boats to Save People
// Link: https://leetcode.com/problems/boats-to-save-people/
// Difficulty: Medium
// Tags: Array, Two Pointers, Greedy, Sorting

// ✅ Approach:
// First, sort the array so we can try pairing the lightest
// and heaviest person together.
//
// Use 2 pointers:
//  1. i → points to the lightest person
//  2. j → points to the heaviest person
//
// Greedy idea:
// - If the lightest + heaviest person can fit in one boat,
//   send them together.
// - Otherwise, the heaviest person must go alone.
//
// In every step, one boat is used.
// Keep doing this until all people are assigned boats.

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        // Sort the people by weight
        sort(begin(people), end(people));

        // Two pointers:
        // i -> lightest person
        // j -> heaviest person
        int i = 0, j = people.size() - 1;

        // Stores the total number of boats needed
        int boat = 0;

        // Continue until all people are assigned
        while(i <= j){

            // If lightest + heaviest can fit in one boat
            if((people[i] + people[j]) <= limit ){
                i++;   // Move lightest forward
                j--;   // Move heaviest backward
            } 
            else {
                // Heaviest person must go alone
                j--;
            }

            // One boat is used in each iteration
            boat++;
        }

        // Return minimum boats needed
        return boat;
    }
};