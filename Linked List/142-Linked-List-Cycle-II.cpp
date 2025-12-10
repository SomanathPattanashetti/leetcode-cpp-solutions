// Leetcode Problem: 142. Linked List Cycle II
// Link: https://leetcode.com/problems/linked-list-cycle-ii/
// Difficulty: Medium
// Tags: Linked List, Two Pointers, Floyd's Cycle Detection

// ✅ Approach: Floyd’s Tortoise and Hare Algorithm
//
// The goal is to detect if a cycle exists in a linked list and return
// the node where the cycle begins.
//
// ### Steps:
//
// 1. Use two pointers: **slow** moves 1 step, **fast** moves 2 steps.
// 2. If there is a cycle, slow and fast will eventually meet inside the cycle.
// 3. If fast reaches NULL, there is **no cycle**, return nullptr.
// 4. Once they meet, reset one pointer (say, `p`) to head.
// 5. Move both `p` and `slow` one step at a time.
// 6. The point where they meet again is the **cycle starting node**.
//
// This works because of the mathematical relationship between the distance 
// from head to cycle start and the meeting point inside the loop.

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(!head || !head->next)
            return nullptr;

        ListNode* fast(head);
        ListNode* slow(head);
        
        // Step 1: Detect cycle
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                break;
        }

        // No cycle found
        if(slow != fast)
            return nullptr;

        // Step 2: Find cycle start
        ListNode* p(head);

        while(p != slow){
            slow = slow->next;
            p = p->next;
        }

        return slow;
    }
};
