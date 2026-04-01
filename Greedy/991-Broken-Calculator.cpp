// Leetcode Problem: 991. Broken Calculator
// Link: https://leetcode.com/problems/broken-calculator/
// Difficulty: Medium
// Tags: Math, Greedy, Recursion

// ✅ Approach:
// Instead of converting startValue → target directly,
// we work in reverse from target → startValue.
//
// Why?
// Because from target side:
//  1. If target is even, it must have come from target/2
//  2. If target is odd, it must have come from target+1
//
// This greedy reverse approach gives the minimum operations.
//
// Base Case:
// If startValue is already greater than or equal to target,
// we only need (startValue - target) decrement operations.

class Solution {
public:
    int brokenCalc(int startValue, int target) {

        // Base Case:
        // If startValue is already bigger or equal,
        // we can only reduce it by subtracting 1
        if(startValue >= target)
            return startValue - target;

        // If target is even,
        // the best reverse step is dividing it by 2
        if(target % 2 == 0) {
            return 1 + brokenCalc(startValue, target / 2);
        }

        // If target is odd,
        // we make it even first by adding 1
        return 1 + brokenCalc(startValue, target + 1);
    }
};