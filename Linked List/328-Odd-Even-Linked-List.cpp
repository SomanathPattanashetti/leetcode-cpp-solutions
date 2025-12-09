// Leetcode Problem: 328. Odd Even Linked List
// Link: https://leetcode.com/problems/odd-even-linked-list/
// Difficulty: Medium
// Tags: Linked List, Two Pointers

// ✅ Approach:
//
// The goal is to rearrange the linked list so that all **odd-indexed nodes**
// come first, followed by all **even-indexed nodes**, while preserving their
// original relative order.
//
// 1. If the list has 0 or 1 node → no change needed, return head.
// 2. Maintain three pointers:
//      - `odd`  → tracks the current odd-indexed node
//      - `even` → tracks the current even-indexed node
//      - `even_start` → stores the start of the even list (to attach later)
// 3. Keep rearranging links:
//      - odd->next = even->next  → links current odd to next odd node
//      - even->next = even->next->next → links current even to next even node
// 4. Move odd and even pointers forward.
// 5. After the loop ends, attach the even list at the end of the odd list:
//      - odd->next = even_start
// 6. Return the head of the adjusted linked list.
//
// This achieves the reordering in **O(n) time** and **O(1) extra space**.

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (!head || !head->next)
            return head;

        ListNode* odd = head;              // Pointer for odd index nodes
        ListNode* even = head->next;       // Pointer for even index nodes
        ListNode* even_start = head->next; // To attach later

        while (even && even->next) {

            odd->next = even->next;        // Link odd to next odd node
            even->next = even->next->next; // Link even to next even node

            odd = odd->next;               // Move odd forward
            even = even->next;             // Move even forward
        }

        odd->next = even_start;            // Attach even list after odd list

        return head;                       // Return reordered list
    }
};
