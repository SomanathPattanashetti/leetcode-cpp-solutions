// Leetcode Problem: 876. Middle of the Linked List
// Link: https://leetcode.com/problems/middle-of-the-linked-list/
// Difficulty: Easy
// Tags: Linked List, Two Pointers

// ✅ Approach:
//
// The goal is to find the middle node of a singly linked list.
// We use the classic **slow & fast pointer (Hare and Tortoise)** technique:
//
// 1. Initialize two pointers: `slow` moves 1 step, `fast` moves 2 steps.
// 2. Traverse the list while `fast` and `fast->next` exist.
// 3. For every move: slow → 1 step, fast → 2 steps.
// 4. When `fast` reaches the end, `slow` will be exactly at the middle node.
// 5. Return the `slow` pointer as the result.
//
// This finds the middle node in **one traversal (O(n))** 
// and uses **constant extra space (O(1))**.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;   // Moves 1 step
        ListNode* fast = head;   // Moves 2 steps
        
        // Move fast by 2 and slow by 1
        while (fast && fast->next) {

            slow = slow->next;         // Slow moves one step
            fast = fast->next->next;   // Fast moves two steps
        }

        // Slow now points to the middle node
        return slow;
    }
};
