/*
    LeetCode 110: Balanced Binary Tree

    Topic: Tree, DFS, Recursion

    Difficulty: Easy

    Tags:
    Binary Tree,
    Depth First Search (DFS),
    Recursion

    ✅ Approach:

    A binary tree is balanced if,
    for every node,

    |height(left subtree) - height(right subtree)| <= 1

    Idea:

    For every node,

    1. Find the height of its left subtree.

    2. Find the height of its right subtree.

    3. Check whether the height difference
       is greater than 1.

    4. Recursively verify that both
       left and right subtrees are
       also balanced.

    Height Formula:

        height(node)

        =
        1 +
        max(
            height(node->left),
            height(node->right)
        )

    Balance Formula:

        balanced(node)

        =
        abs(
            leftHeight - rightHeight
        ) <= 1

        &&
        balanced(node->left)

        &&
        balanced(node->right)

    Base Cases:

    getHeight()

    If node is NULL,
    return 0.

    isBalanced()

    If node is NULL,
    return true.

    Why it works:

    - Every node checks the height
      of its left and right subtree.

    - If the difference is more than 1,
      the tree is not balanced.

    - Even if the current node is balanced,
      both left and right subtrees must
      also be balanced.

    - Recursively checking every node
      guarantees the entire tree satisfies
      the balance condition.

    Example:

             3
            / \
           9   20
              /  \
             15   7

    Heights:

        height(9)  = 1
        height(15) = 1
        height(7)  = 1

        height(20) = 2
        height(3)  = 3

    Balance Check:

        Node 20:

        |1 - 1| = 0 ✓

        Node 3:

        |1 - 2| = 1 ✓

    Tree is Balanced.

    Recursive Flow:

        isBalanced(3)

        ├── getHeight(9)
        ├── getHeight(20)
        │      ├── getHeight(15)
        │      └── getHeight(7)
        │
        ├── isBalanced(9)
        └── isBalanced(20)
               ├── isBalanced(15)
               └── isBalanced(7)

    Time Complexity:

    O(N²)

    Why?

    For every node,
    getHeight() traverses its subtree
    again.

    In a skewed tree,

        N + (N-1) + (N-2) + ...

    = O(N²)

    Best Case:

    Approximately O(N log N)
    for a balanced tree.

    Worst Case:

    O(N²)
    for a skewed tree.

    Space Complexity:

    O(H)

    H = Height of tree

    Due to recursive call stack.

    Worst Case:

    O(N)

    Best Case:

    O(log N)

*/

class Solution {
public:

    // Returns height of a subtree
    int getHeight(TreeNode* root){

        // Empty subtree has height 0
        if(!root)
            return 0;

        // Height = 1 + maximum height
        // of left and right subtree
        return 1 + max(
            getHeight(root->left),
            getHeight(root->right)
        );
    }

    bool isBalanced(TreeNode* root) {

        // Empty tree is balanced
        if(!root)
            return true;

        // Find left subtree height
        int left_height = getHeight(root->left);

        // Find right subtree height
        int right_height = getHeight(root->right);

        // Height difference greater than 1
        // means tree is not balanced
        if(abs(left_height - right_height) > 1)
            return false;

        // Both left and right subtree
        // must also be balanced
        return isBalanced(root->left)
            && isBalanced(root->right);
    }
};