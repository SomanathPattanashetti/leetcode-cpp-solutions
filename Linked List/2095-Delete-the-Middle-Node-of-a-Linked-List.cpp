// Leetcode Problem: 2095. Delete the Middle Node of a Linked List
// Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Difficulty: Medium
// Tags: Linked List, Two Pointers

// ✅ Approach:
//
// The goal is to delete the middle node of a singly linked list.
// We use the classic **slow & fast pointer** method:
//
// 1. If the list has 0 or 1 node → return nullptr (middle doesn't exist).
// 2. Use `slow` to move one step at a time and `fast` to move two steps.
// 3. Maintain `prev_slow` which always stays one step behind `slow`.
// 4. When `fast` reaches the end, `slow` will be at the middle node.
// 5. Unlink the middle node by doing: prev_slow->next = slow->next.
// 6. Delete the middle node to free memory.
// 7. Return the original head pointer.
//
// This efficiently deletes the middle node in **one traversal (O(n))** 
// and uses **constant extra space (O(1))**.

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // Edge case: list empty or only 1 node
        if (!head || !head->next)
            return nullptr;

        ListNode* fast = head;       // Moves 2 steps
        ListNode* slow = head;       // Moves 1 step (will reach middle)
        ListNode* prev_slow = head;  // Tracks node before slow

        // Traverse until fast reaches end
        while (fast && fast->next) {
            prev_slow = slow;           // Store previous node
            slow = slow->next;          // Move slow by 1
            fast = fast->next->next;    // Move fast by 2
        }

        // Remove the middle node
        prev_slow->next = slow->next;
        delete slow;

        return head;  // return updated list
    }
};
