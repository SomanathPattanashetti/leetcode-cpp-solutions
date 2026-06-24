/*
    LeetCode 226: Invert Binary Tree

    Topic: Tree, DFS, Recursion

    Difficulty: Easy

    Tags:
    Binary Tree,
    Depth First Search (DFS),
    Recursion

    ✅ Approach:

    Invert a binary tree by swapping
    the left and right child of every node.

    Idea:

    Visit every node using DFS.

    For each node:

    1. Invert left subtree.

    2. Invert right subtree.

    3. Swap left and right children.

    Recursive Formula:

        invert(root)

        invert(root->left)
        invert(root->right)

        swap(
            root->left,
            root->right
        )

    Base Case:

    If root is NULL,
    return NULL.

    Why it works:

    - Every node exchanges its
      left and right child.

    - Since recursion first processes
      both subtrees, all descendants
      are inverted before swapping
      at the current node.

    - Repeating this for every node
      produces the mirror image
      of the original tree.

    Example:

            4
          /   \
         2     7
        / \   / \
       1   3 6   9

    After Inversion:

            4
          /   \
         7     2
        / \   / \
       9   6 3   1

    DFS Flow:

        invert(4)

        ├── invert(2)
        │   ├── invert(1)
        │   └── invert(3)
        │
        │   swap(1, 3)
        │
        └── invert(7)
            ├── invert(6)
            └── invert(9)

            swap(6, 9)

        swap(2, 7)

    Final Tree:

            4
          /   \
         7     2
        / \   / \
       9   6 3   1

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

    TreeNode* invertTree(TreeNode* root) {

        // Empty tree
        if(!root)
            return NULL;

        // Invert left subtree
        root->left = invertTree(root->left);

        // Invert right subtree
        root->right = invertTree(root->right);

        // Swap left and right child
        swap(root->left, root->right);

        // Return updated root
        return root;
    }
};