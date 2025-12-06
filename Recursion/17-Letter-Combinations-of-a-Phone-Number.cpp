// Leetcode Problem: 17. Letter Combinations of a Phone Number
// Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Difficulty: Medium
// Tags: String, Backtracking, Recursion, Mapping

// ✅ Approach:
// Use Backtracking to generate all possible letter combinations
// for the given digit string.
//
// Each digit maps to a set of characters (as on a phone keypad).
// At each index, we try inserting each possible character into
// the current combination and recurse for the next digit.
//
// Steps:
// 1️⃣ Create a digit→letters map (2 → "abc", 3 → "def", ...).
// 2️⃣ Use a recursive function solve(idx):
//      - If idx reaches digits.size(), store the built string.
//      - Otherwise, iterate over all letters of digits[idx].
// 3️⃣ Push a letter → recurse → pop it (backtracking).
//
// Base case: when we've chosen a letter for each digit,
// the temporary string becomes one valid combination.
//
// Note: If digits is empty, the result is empty.

class Solution {
public:
    
    vector<string> res;  // Stores all letter combinations

    // 🔍 Recursive backtracking function
    void solve(string& digits, int idx, string& temp, unordered_map<char,string>& mp) {

        // Base Case: full combination formed
        if(idx >= digits.length()) {
            res.push_back(temp);
            return;
        }

        // Get the letters for current digit
        char ch = digits[idx];
        string str = mp[ch];

        // Try each letter mapped to this digit
        for(int i = 0; i < str.length(); i++) {

            temp.push_back(str[i]);              // Choose a letter
            solve(digits, idx + 1, temp, mp);    // Recurse for next digit
            temp.pop_back();                     // Backtrack
        }
    }

    vector<string> letterCombinations(string digits) {

        // Edge case: no digits → no combinations
        if(digits.empty()) return res;

        // Digit-to-letter mapping
        unordered_map<char,string> mp{
            {'2', "abc"}, {'3', "def"},
            {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        string temp = "";

        solve(digits, 0, temp, mp);  // Start recursion

        return res;
    }
};
