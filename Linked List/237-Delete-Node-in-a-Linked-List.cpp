// Leetcode Problem: 237. Delete Node in a Linked List
// Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
// Difficulty: Medium
// Tags: Linked List

// ✅ Approach:
// Since we are NOT given the head of the linked list, we cannot delete the node normally.
// Instead, we use a trick:
//
// 1. Copy the value of next node into the current node.
// 2. Move forward and keep copying values until we reach the last node.
// 3. Keep track of the previous node while shifting values.
// 4. Once we reach the last node, unlink it by setting prev->next = nullptr.
// 5. Finally delete the last node.
//
// This effectively removes the originally given node without needing the head pointer.

class Solution {
public:
    void deleteNode(ListNode* node) {

        ListNode* prev(nullptr);  // To track the previous node

        // Traverse forward while shifting values
        while(node && node->next) {

            node->val = node->next->val;  // Copy next node's value
            prev = node;                  // Update prev
            node = node->next;            // Move forward
        }

        // Unlink the last node
        prev->next = nullptr;

        // Delete the tail node (free memory)
        delete node;
    }
};
