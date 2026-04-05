// Leetcode Problem: 1833. Maximum Ice Cream Bars
// Link: https://leetcode.com/problems/maximum-ice-cream-bars/
// Difficulty: Medium
// Tags: Array, Greedy, Sorting

// ✅ Approach:
// Sort the ice cream costs in ascending order.
// Always try to buy the cheapest ice cream first.
// This greedy approach helps us maximize the number of bars bought.
//
// Traverse through the sorted costs:
// - If the current cost is affordable, buy it
// - Deduct the cost from coins
// - Increase the count
//
// If a cost is greater than remaining coins, stop immediately
// because all next costs will also be greater or equal.

class Solution {     
public:
    int maxIceCream(vector<int>& costs, int coins) {

        // Sort all ice cream costs in increasing order
        std::sort(begin(costs), end(costs));
        
        int count = 0;  // Stores number of ice creams bought

        // Traverse each ice cream cost
        for(auto& cost : costs){

            // If current ice cream is too expensive, stop buying
            if(cost > coins)
                return count;
            else{
                // Buy this ice cream
                count++;

                // Reduce the remaining coins
                coins -= cost;
            }
        }

        // Return total ice creams bought
        return count;
    }
};