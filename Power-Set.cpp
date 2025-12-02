// GFG Problem: Power Set (All Possible Strings)
// Link: https://www.geeksforgeeks.org/problems/power-set4302/1
// Difficulty: Easy
// Tags: String, Backtracking

// ✅ Approach:
// Use Backtracking to generate all possible non-empty subsequences.
// At each index in the string, we have 2 choices:
//   1. Include the current character in the temporary string
//   2. Exclude the current character
//
// We explore both choices recursively.
// When we reach the end of the string, we add the current built string (temp)
// to the answer—only if it is non-empty.
// Finally, we sort the result as required by GFG.

class Solution {
public:
    vector<string> res;  // Stores all subsequences (non-empty)

    // Recursive function to generate all subsequences
    void solve(string& s, int idx, string& temp) {

        // Base Case:
        // When index reaches the end of the string
        if (idx >= s.length()) {

            // Store only non-empty subsequences
            if (temp != "") {
                res.push_back(temp);
            }
            return;
        }

        // 🔹 Choice 1: Include s[idx] in the current string
        temp.push_back(s[idx]);
        solve(s, idx + 1, temp);

        // Backtrack: remove last added character
        temp.pop_back();

        // 🔹 Choice 2: Exclude s[idx] and move further
        solve(s, idx + 1, temp);
    }

    vector<string> AllPossibleStrings(string s) {

        string temp = "";  // Temporary string to build subsequences

        solve(s, 0, temp);  // Start at index 0

        // GFG wants output in lexicographical order
        sort(res.begin(), res.end());

        return res;
    }
};
