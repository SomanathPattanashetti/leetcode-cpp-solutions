// Leetcode Problem: 859. Buddy Strings
// Link: https://leetcode.com/problems/buddy-strings/
// Difficulty: Easy
// Tags: String, Hashing

// ✅ Problem Understanding:
// We are given two strings s and goal.
// We can swap exactly ONE pair of characters in s.
// Return true if after swap s becomes equal to goal.

// There are ONLY 2 valid cases:
//
// 1️⃣ s == goal
//     Then swapping must not change the string.
//     This is possible only if any character appears at least twice.
//     Example: "aa" -> swap a & a -> still "aa"
//
// 2️⃣ s != goal
//     Then exactly TWO indices must be different.
//     After swapping those two characters in s,
//     the string must match goal.

class Solution {
public:

    // 🔹 Helper function:
    // Checks if any character appears more than once
    // Needed when s == goal
    bool checkFreq(string& s){
        
        int freq[26]{};   // frequency array for a-z

        for(auto& ch : s){
            
            freq[ch - 'a']++;

            // If any character repeats, swap is valid
            if(freq[ch-'a'] > 1)
                return true;
        }

        return false;
    }

    bool buddyStrings(string s, string goal) {

        // Step 1: Length must be same
        if(s.length() != goal.length())
            return false;

        // Step 2: If both strings already equal
        // We need duplicate character to allow a valid swap
        if(s == goal){
            return checkFreq(s);
        }

        // Step 3: Find mismatched indices
        vector<int> indexs;
        int n = s.length();

        for(int i=0; i<n; i++){

            if(s[i] != goal[i])
                indexs.push_back(i);

        }

        // Exactly 2 mismatches required
        if(indexs.size() != 2)
            return false;

        // Step 4: Swap those two characters in s
        swap(s[indexs[0]],s[indexs[1]]);

        // Step 5: Check if strings become equal
        return s == goal;
    }
};
859