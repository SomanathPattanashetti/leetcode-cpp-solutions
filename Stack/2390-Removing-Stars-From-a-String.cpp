// Leetcode Problem: 2390. Removing Stars From a String
// Link: https://leetcode.com/problems/removing-stars-from-a-string/
// Difficulty: Medium
// Tags: String, Stack, Simulation

// ✅ Approach:
// We simulate the process using a string as a stack.
//
// Traverse each character in the string:
// 1. If the character is NOT '*', push it into the result string.
// 2. If the character IS '*', remove the last added character
//    (pop from result), which mimics removing the closest non-star
//    character to the left.
//
// This works because:
// - The problem guarantees a valid removal for every '*'
// - A string can act as a stack using push_back() and pop_back()

class Solution {
public:
    string removeStars(string s) {
        string result = ""; // Acts like a stack to store final characters
        
        for(char &ch : s) {
            
            // If star is found, remove the previous character
            if(ch == '*') {
                result.pop_back();
            }
            // Otherwise, add the character to result
            else {
                result.push_back(ch);
            }
        }
        
        // The result string contains the final answer
        return result;
    }
};
