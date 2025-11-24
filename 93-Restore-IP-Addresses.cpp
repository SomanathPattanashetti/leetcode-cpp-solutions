// Leetcode Problem: 93. Restore IP Addresses
// Link: https://leetcode.com/problems/restore-ip-addresses/
// Difficulty: Medium
// Tags: String, Backtracking

// ✅ Approach:
// We need to split the given numeric string into **4 valid IP segments**.
// Each segment must:
//   • Be between 0–255
//   • Not have leading zeros (e.g., "01", "001" are invalid)
//
// We use **Backtracking** to try taking 1, 2, or 3 characters at a time,
// but only if the segment is valid. When we form exactly 4 segments and
// reach the end of the string, we add the constructed IP to result.
//
// Key Idea:
// - At each index, try forming a segment of length 1, 2, or 3
// - Validate it (≤255 and no leading zero)
// - Append to temp string with a dot
// - Recursively build the remaining parts
// - When idx==n and parts==4 → valid IP found

class Solution {
public:
    vector<string> res;   // Stores all valid IP addresses
    int n;

    // Function to check if a segment is valid:
    // - Cannot start with '0' unless it's just "0"
    // - Must be ≤255
    bool isvalid(string s){
        return s[0] != '0' && stoi(s) <= 255;
    }

    // Backtracking function
    void solve(string& s, int idx, int parts, string temp){

        // Base Case: all characters used + exactly 4 parts formed
        if(idx == n && parts == 4){
            temp.pop_back();      // Remove last dot
            res.push_back(temp);  // Store valid IP
            return;
        }

        // 🔹 Option 1: Take 1 digit
        if(idx + 1 <= n)
            solve(s, idx + 1, parts + 1, temp + s.substr(idx, 1) + ".");

        // 🔹 Option 2: Take 2 digits (must be valid)
        if(idx + 2 <= n && isvalid(s.substr(idx, 2)))
            solve(s, idx + 2, parts + 1, temp + s.substr(idx, 2) + ".");

        // 🔹 Option 3: Take 3 digits (must be valid)
        if(idx + 3 <= n && isvalid(s.substr(idx, 3)))
            solve(s, idx + 3, parts + 1, temp + s.substr(idx, 3) + ".");
    }

    vector<string> restoreIpAddresses(string s) {
        string temp = "";
        n = s.length();

        // Optimization: Max length valid IP = 12 digits (4 segments * 3 digits)
        if(n > 12) return {};

        solve(s, 0, 0, temp);   // Start backtracking from index 0

        return res;
    }
};
