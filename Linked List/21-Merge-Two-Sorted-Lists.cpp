// Leetcode Problem: 21. Merge Two Sorted Lists
// Link: https://leetcode.com/problems/merge-two-sorted-lists/
// Difficulty: Easy
// Tags: Linked List, Recursion

// ✅ Approach:
// We merge two sorted linked lists using recursion.
// At each step, we compare the current nodes of both lists.
// The smaller value node becomes part of the merged list,
// and we recursively merge the remaining nodes.
//
// 🔹 Key Idea:
// - Always pick the smaller node between l1 and l2
// - Attach it to the result
// - Move forward in the list from which the node was taken
//
// This naturally maintains the sorted order.

class Solution {
public:
    // Recursive function to merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        // Base Case 1:
        // If first list is empty, return second list
        if(!l1)
            return l2;

        // Base Case 2:
        // If second list is empty, return first list
        if(!l2)
            return l1;

        // 🔹 If current node of l1 is smaller or equal
        // Choose l1 node and merge the rest
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;   // l1 becomes head of merged list
        }
        // 🔹 If current node of l2 is smaller
        // Choose l2 node and merge the rest
        else{
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;   // l2 becomes head of merged list
        }
    }
};
