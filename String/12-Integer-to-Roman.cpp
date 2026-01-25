// Leetcode Problem: 12. Integer to Roman
// Link: https://leetcode.com/problems/integer-to-roman/
// Difficulty: Medium
// Tags: Math, String, Greedy

// ✅ Approach:
// Use a Greedy strategy to convert the integer into Roman numerals.
//
// Roman numerals are formed by using the largest possible symbol first.
// We maintain two arrays:
//  1. `values`  → Integer values in descending order
//  2. `symbols` → Corresponding Roman symbols
//
// For each value:
//  - Check how many times it fits into the current number
//  - Append the corresponding Roman symbol that many times
//  - Reduce the number accordingly
//
// Continue until the number becomes 0.

class Solution {
public:
    string intToRoman(int num) {

        // Integer values mapped to Roman symbols (ordered from large to small)
        vector<int> values{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> symbols{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string res;  // Stores final Roman numeral result

        // Iterate through all Roman values
        for(int i = 0; i < 13; i++) {

            // If number becomes zero, conversion is complete
            if(num == 0)
                break;

            // Find how many times current value fits into num
            int time = num / values[i];

            // Append the Roman symbol 'time' number of times
            while(time--) {
                res += symbols[i];
            }

            // Reduce num by removing the processed value
            num = num % values[i];
        }

        return res;  // Final Roman numeral string
    }
};