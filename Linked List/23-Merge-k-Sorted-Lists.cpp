// Leetcode Problem: 23. Merge k Sorted Lists
// Link: https://leetcode.com/problems/merge-k-sorted-lists/
// Difficulty: Hard
// Tags: Linked List, Divide and Conquer, Recursion

// ✅ Approach:
// We use the Divide and Conquer technique to merge k sorted linked lists efficiently.
//
// Steps:
// 1. Recursively divide the list of linked lists into two halves.
// 2. Merge each half using a helper function that merges two sorted linked lists.
// 3. Continue merging until all lists are combined into one sorted list.
//
// This approach reduces time complexity compared to merging lists one by one.

class Solution {
public:

    // 🔹 Helper function to merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        // Base Case:
        // If first list is empty, return second list
        if(!l1)
            return l2;

        // If second list is empty, return first list
        if(!l2)
            return l1;

        // Compare current nodes of both lists
        if(l1->val <= l2->val) {
            // Choose l1 node and recursively merge remaining lists
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            // Choose l2 node and recursively merge remaining lists
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }

    // 🔹 Function to divide the list of linked lists and merge them
    ListNode* partitionAndMerge(vector<ListNode*>& lists, int start, int end) {

        // Base Case:
        // If range is invalid, return NULL
        if(start > end)
            return nullptr;

        // If only one list exists, return it
        if(start == end)
            return lists[start];

        // Divide the range into two halves
        int mid = (start + end) / 2;

        // Recursively merge left half
        ListNode* L1 = partitionAndMerge(lists, start, mid);

        // Recursively merge right half
        ListNode* L2 = partitionAndMerge(lists, mid + 1, end);

        // Merge the two sorted halves
        return mergeTwoLists(L1, L2);
    }

    // 🔹 Main function to merge k sorted lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int k = lists.size();

        // Start divide-and-conquer from index 0 to k-1
        return partitionAndMerge(lists, 0, k - 1);
    }
};
