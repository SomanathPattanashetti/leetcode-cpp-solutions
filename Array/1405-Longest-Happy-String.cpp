// Leetcode Problem: 1405. Longest Happy String
// Link: https://leetcode.com/problems/longest-happy-string/
// Difficulty: Medium
// Tags: Greedy, Heap (Priority Queue), String

// ✅ Approach:
// Use a Max Heap (Priority Queue) to always pick the character
// with the highest remaining frequency.
//
// Rules to follow:
// - We cannot place the same character 3 times consecutively.
// - If the most frequent character causes 3 consecutive repeats,
//   we temporarily use the next most frequent character.
//
// Steps:
// 1. Push available characters (a, b, c) with their frequencies into a max heap.
// 2. Repeatedly extract the character with highest frequency.
// 3. Check if adding it violates the "no 3 consecutive characters" rule.
// 4. If violation occurs, pick the next best character from the heap.
// 5. Append characters greedily while maintaining constraints.

class Solution {
public:
    typedef pair<int, char> P;  // {frequency, character}

    string longestDiverseString(int a, int b, int c) {

        // Max Heap to store characters by highest frequency
        priority_queue<P> pq;

        // Push characters only if their frequency > 0
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        string res = "";  // Resultant happy string

        // Continue until heap is empty
        while(!pq.empty()) {

            // Pick the character with highest frequency
            auto [curr_ch_freq, curr_ch] = pq.top();
            pq.pop();

            // ❌ Check if adding this character causes 3 consecutive repeats
            if(res.length() >= 2 &&
               res[res.length() - 1] == curr_ch &&
               res[res.length() - 2] == curr_ch) {

                // If no other character is available, stop
                if(pq.empty()) {
                    break;
                }

                // Pick the next most frequent character
                auto [next_ch_freq, next_ch] = pq.top();
                pq.pop();

                // Add the next character to result
                res.push_back(next_ch);
                next_ch_freq--;

                // Push back if frequency remains
                if(next_ch_freq > 0)
                    pq.push({next_ch_freq, next_ch});
            }
            else {
                // ✅ Safe to add current character
                res.push_back(curr_ch);
                curr_ch_freq--;
            }

            // Push back current character if frequency remains
            if(curr_ch_freq > 0) {
                pq.push({curr_ch_freq, curr_ch});
            }
        }

        return res;  // Longest possible happy string
    }
};
