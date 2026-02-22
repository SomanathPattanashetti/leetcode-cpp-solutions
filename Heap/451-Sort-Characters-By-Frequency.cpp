// Leetcode Problem: 451. Sort Characters By Frequency
// Link: https://leetcode.com/problems/sort-characters-by-frequency/
// Difficulty: Medium
// Tags: Hash Map, Heap (Priority Queue), Sorting, String

// ✅ Approach:
// Count frequency of each character using HashMap.
// Then use a Max Heap (priority_queue) to always get the character
// with highest frequency first.
//
// Steps:
// 1. Traverse string and store frequency in map
// 2. Push (frequency, character) pair into max heap
// 3. Pop from heap and append character 'frequency' times into result string
//
// Why Max Heap?
// Because we need characters in decreasing order of frequency.
// priority_queue in C++ by default is max heap → perfect for this problem.

class Solution {
public:
    string frequencySort(string s) {

        // Step 1: Count frequency of each character
        unordered_map<char, int> mp;

        for(auto& ch : s){
            mp[ch]++;              // Increment count
        }

        // Step 2: Max Heap -> stores {frequency, character}
        priority_queue<pair<int, char>> pq;

        for(auto& [ch, freq] : mp){
            pq.push({freq, ch});   // Highest frequency stays at top
        }

        string res;

        // Step 3: Build result string
        while(!pq.empty()){

            auto [freq, ch] = pq.top();
            pq.pop();

            // Append character 'freq' times
            res += string(freq, ch);
        }

        return res;
    }
};