// Leetcode Problem: 109. Convert Sorted List to Binary Search Tree
// Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
// Difficulty: Medium
// Tags: Linked List, Two Pointers, Divide & Conquer, Binary Search Tree

// ✅ Approach:
//
// The goal is to convert a **sorted singly linked list** into a height-balanced
// Binary Search Tree (BST).
//
// Since the list is sorted, the **middle element becomes the root**, the left
// half becomes the left subtree, and the right half becomes the right subtree.
// This follows the same logic as converting a sorted array to a BST.
//
// But unlike arrays, we cannot directly index into the middle of a linked list.
// So we use the **slow–fast pointer technique**:
//
// Steps:
// 1. If the list is empty → return NULL.
// 2. If the list has only one node → that node becomes a leaf TreeNode.
// 3. Use `slow` and `fast` pointers to find the **middle node**.
//      - `slow` → middle node
//      - `fast` → moves twice as fast
//      - `prev_slow` → node before slow (to break the list later)
// 4. Middle node (`slow`) becomes the **root** of the BST.
// 5. Break the list into two halves by doing `prev_slow->next = NULL`.
// 6. Recursively convert:
//      - Left half → root->left
//      - Right half → root->right
//
// Time Complexity:  O(n log n)  
// Space Complexity: O(log n) due to recursion stack
//
// This ensures a **balanced BST** is constructed from the sorted linked list.

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {

        // Base case: empty list
        if (!head)
            return nullptr;

        // Base case: single node becomes a leaf in BST
        if (!head->next)
            return new TreeNode(head->val);

        // Slow–Fast pointers to find the middle
        ListNode* prev_slow = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev_slow = slow;      // Track previous of slow
            slow = slow->next;     // Move slow by 1
            fast = fast->next->next; // Move fast by 2
        }

        // Middle value becomes the root of BST
        TreeNode* root = new TreeNode(slow->val);

        // Cut the list into two halves
        prev_slow->next = nullptr;

        // Left part: from head to prev_slow
        root->left  = sortedListToBST(head);

        // Right part: from slow->next to end
        root->right = sortedListToBST(slow->next);

        return root;
    }
};
