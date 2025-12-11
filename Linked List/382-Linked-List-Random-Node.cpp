// Leetcode Problem: 382. Linked List Random Node
// Link: https://leetcode.com/problems/linked-list-random-node/
// Difficulty: Medium
// Tags: Linked List, Reservoir Sampling, Randomized

// ✅ Approach:
//
// The goal is to return a **random node's value** from a singly linked list,
// where each node must have an equal probability of being chosen.
//
// In this approach, we store **all values of the linked list in a vector**
// during construction. Then every time `getRandom()` is called, we simply
// pick a random index and return that value.
//
// Steps:
// 1. Traverse the linked list once in the constructor.
// 2. Store each node's value in a vector `list`.
// 3. For every `getRandom()` call:
//      - Generate a random index using `rand() % n`.
//      - Return the value stored at that index.
// 4. This gives **O(1)** time random access for each call.
// 5. Memory usage is **O(n)** because we store the entire list.
//
// This is a straightforward approach and works efficiently for repeated
// random queries, though it uses extra space compared to reservoir sampling.

class Solution {
public:
    vector<int> list;  // Stores all node values
    
    // Constructor: Convert linked list into an array
    Solution(ListNode* head) {
        
        ListNode* temp = head;

        while (temp) {
            list.push_back(temp->val); // Store each value
            temp = temp->next;
        }
    }
    
    // Returns a random value from the list
    int getRandom() {

        int n = list.size();          // Total elements
        int random_idx = rand() % n;  // Generate random index

        return list[random_idx];      // Return random element
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
