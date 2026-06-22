/*
    LeetCode 101: Symmetric Tree

    Topic: Tree, DFS, Recursion

    Difficulty: Easy

    Tags:
    Binary Tree,
    Depth First Search (DFS),
    Recursion

    ✅ Approach:

    A binary tree is symmetric if its
    left subtree is a mirror image
    of its right subtree.

    Idea:

    Compare two nodes at a time.

    For two nodes to be mirrors:

    1. Their values must be equal.

    2. Left child of first node
       must match right child
       of second node.

    3. Right child of first node
       must match left child
       of second node.

    Recursive Formula:

        mirror(p, q) =

        p->val == q->val

        &&
        mirror(p->left, q->right)

        &&
        mirror(p->right, q->left)

    Base Cases:

    1. If both nodes are NULL,
       return true.

    2. If one node is NULL and
       the other is not,
       return false.

    Why it works:

    - Symmetry means both sides
      should look exactly the same
      when one side is reflected.

    - DFS recursively compares
      opposite children.

    - Every pair of mirror nodes
      must satisfy the mirror condition.

    Example:

                1
              /   \
             2     2
            / \   / \
           3   4 4   3

    Comparisons:

        2 == 2 ✓

        3 == 3 ✓
        4 == 4 ✓

    All mirror comparisons succeed.

    Output:

        true

    DFS Flow:

        check(2, 2)
        ├── check(3, 3)
        │   ├── check(NULL, NULL)
        │   └── check(NULL, NULL)
        │
        │   return true
        │
        └── check(4, 4)
            ├── check(NULL, NULL)
            └── check(NULL, NULL)

            return true

        return true

    Example (Not Symmetric):

            1
           / \
          2   2
           \   \
            3   3

    Comparison:

        left->left  = NULL
        right->right = 3

    Mirror condition fails.

    Output:

        false

    Time Complexity:

    O(N)

    where N is the number of nodes.

    Every node is visited once.

    Space Complexity:

    O(H)

    H = height of tree

    Due to recursive call stack.

    Worst Case:
    O(N)  (skewed tree)

    Best Case:
    O(log N) (balanced tree)

*/

class Solution {
public:

    bool check(TreeNode* p, TreeNode* q) {

        // Both nodes are NULL
        // Mirror condition satisfied
        if(!p && !q)
            return true;

        // One node exists and
        // the other does not
        if(!p || !q)
            return false;

        // Values must be equal
        // and opposite children
        // must also be mirrors
        return p->val == q->val &&
               check(p->left, q->right) &&
               check(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {

        // Compare left subtree
        // with right subtree
        return check(
            root->left,
            root->right
        );
    }
};