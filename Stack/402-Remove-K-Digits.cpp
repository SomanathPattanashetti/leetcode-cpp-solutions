// Leetcode Problem: 402. Remove K Digits
// Link: https://leetcode.com/problems/remove-k-digits/
// Difficulty: Medium
// Tags: Greedy, Stack, String, Monotonic Stack

// ✅ Approach:
// We want the smallest possible number after removing k digits.
//
// Key Greedy Idea:
// Digits on the LEFT have higher place value.
// So whenever a smaller digit appears, we should remove previous bigger digits.
//
// We simulate a MONOTONIC INCREASING STACK using a string:
//  - If current digit < last digit → pop from stack (remove bigger digit)
//  - Continue while we can remove and k > 0
//
// Leading Zero Handling:
// We avoid pushing '0' if result is empty (prevents numbers like "00023").
//
// After traversal:
// If k still remains, remove digits from the END (largest remaining digits).
//
// Finally:
// If result becomes empty → return "0"

class Solution {
public:
    string removeKdigits(string num, int k) {

        // If we remove all digits → smallest number is 0
        if(num.size() == k){
            return "0";
        }

        string res; // acts like a stack

        // Traverse each digit
        for(auto& no : num){
            
            // Remove previous bigger digits to minimize number
            while(res.length() > 0 && k > 0 && res.back() > no){
                res.pop_back();
                k--;
            }

            // Avoid leading zeros
            if(res.length() > 0 || no != '0')
                res.push_back(no);
        }

        // If removals still left → remove from end
        while(res.length() > 0 && k > 0){
            res.pop_back();
            k--;
        }

        // If empty → return 0
        if(res == "")
            return "0";

        return res;
    }
};
