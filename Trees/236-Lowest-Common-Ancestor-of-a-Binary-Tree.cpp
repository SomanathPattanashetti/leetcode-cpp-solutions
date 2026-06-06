/*
    LeetCode 236: Lowest Common Ancestor of a Binary Tree
    Topic: Binary Tree, Recursion

    Difficulty: Medium

    Tags:
    Tree, Binary Tree,
    Depth First Search (DFS), Recursion

    ✅ Approach:
    This solution uses Recursive DFS
    to find the Lowest Common Ancestor (LCA)
    of two given nodes in a binary tree.

    Lowest Common Ancestor (LCA):
    The deepest node that has both
    p and q as descendants.

    A node can also be a descendant
    of itself.

    Idea:
    Traverse the tree recursively.

    Cases:
    1. If current node is NULL:
       Return NULL.

    2. If current node is either p or q:
       Return current node.

    3. Search in left subtree.

    4. Search in right subtree.

    5. If both left and right return
       non-NULL values:
       Current node is the LCA.

    6. Otherwise return whichever
       side is non-NULL.

    Why it works:
    - If p and q are found in different
      subtrees, current node becomes
      their first common ancestor.

    - If both nodes are in the same
      subtree, that subtree's result
      propagates upward.

    Example:

              3
             / \
            5   1
           / \ / \
          6  2 0  8
            / \
           7   4

    LCA(5, 1) = 3
    LCA(7, 4) = 2
    LCA(5, 4) = 5

    Time Complexity:
    O(N)
    -> Every node is visited once.

    Space Complexity:
    O(H)
    -> Recursive call stack

    Worst Case:
    O(N)  (Skewed Tree)

    Best/Average Case:
    O(log N) (Balanced Tree)
*/

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* p,
                                   TreeNode* q) {

        // Base Case:
        // Reached end of path
        if(!root)
            return nullptr;

        // If current node is either
        // p or q, return it
        if(root == p || root == q)
            return root;

        // Search in left subtree
        TreeNode* left =
            lowestCommonAncestor(root->left, p, q);

        // Search in right subtree
        TreeNode* right =
            lowestCommonAncestor(root->right, p, q);

        // If both sides found a node,
        // current node is LCA
        if(left && right)
            return root;

        // Return the non-null result
        return left ? left : right;
    }
};