// Leetcode Problem: 1721. Swapping Nodes in a Linked List
// Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
// Difficulty: Medium
// Tags: Linked List, Two Pointers

// ✅ Approach:
// We find the k-th node from the beginning (p1)
// and the k-th node from the end (p2) in a single traversal.
//
// Idea:
// 1. Traverse the list using a temporary pointer (temp).
// 2. When k becomes 0, temp is at the k-th node from the start → mark it as p1.
// 3. At the same time, initialize p2 to head.
// 4. After that, move p2 one step forward for every remaining step of temp.
//    This way, when temp reaches the end, p2 reaches the k-th node from the end.
// 5. Finally, swap the values of p1 and p2.

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* p1 = NULL;  // Will point to k-th node from start
        ListNode* p2 = NULL;  // Will point to k-th node from end

        ListNode* temp = head; // Used for traversing the list

        // Traverse the entire linked list
        while (temp) {

            // Once p2 is initialized, move it forward
            if (p2 != NULL)
                p2 = p2->next;

            // Decrease k on each step
            k--;

            // When k becomes 0:
            // temp is at the k-th node from the beginning
            if (k == 0) {
                p1 = temp;     // Store k-th node from start
                p2 = head;     // Start p2 from head
            }

            temp = temp->next; // Move to next node
        }

        // Swap values of k-th node from start and k-th node from end
        swap(p1->val, p2->val);

        return head; // Return modified list
    }
};
