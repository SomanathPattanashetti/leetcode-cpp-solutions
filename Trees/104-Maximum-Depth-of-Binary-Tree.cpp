/*
    LeetCode 104: Maximum Depth of Binary Tree

    Topic: Tree, DFS, Recursion

    Difficulty: Easy

    Tags:
    Binary Tree,
    Depth First Search (DFS),
    Recursion

    ✅ Approach:

    The depth of a binary tree is the
    number of nodes present in the
    longest path from the root node
    down to any leaf node.

    Idea:

    For every node:

    1. Find the depth of its left subtree.

    2. Find the depth of its right subtree.

    3. Take the maximum of both depths.

    4. Add 1 for the current node.

    Recursive Formula:

        depth(node) =
        1 + max(
                depth(node->left),
                depth(node->right)
            )

    Base Case:

    If the node is NULL,
    return 0.

    Why it works:

    - DFS recursively explores both
      left and right subtrees.

    - Every recursive call returns
      the height/depth of that subtree.

    - The current node contributes
      one level to the depth.

    - Taking the maximum ensures we
      follow the longest root-to-leaf path.

    Example:

            3
           / \
          9   20
             /  \
            15   7

    Leaf depths:

        9  -> 1
        15 -> 1
        7  -> 1

    Node 20:

        1 + max(1, 1)
        = 2

    Root 3:

        1 + max(1, 2)
        = 3

    Output:

        3

    DFS Flow:

        dfs(3)
        ├── dfs(9)
        │   ├── dfs(NULL) = 0
        │   └── dfs(NULL) = 0
        │
        │   return 1
        │
        └── dfs(20)
            ├── dfs(15)
            │   return 1
            │
            └── dfs(7)
                return 1

            return 2

        return 3

    Time Complexity:

    O(N)

    where N is the number of nodes.

    Every node is visited exactly once.

    Space Complexity:

    O(H)

    H = height of the tree

    Due to recursive call stack.

    Worst Case:
    O(N)  (skewed tree)

    Best Case:
    O(log N) (balanced tree)

*/

class Solution {
public:

    int dfs(TreeNode* root) {

        // Base Case:
        // Empty tree contributes
        // depth 0
        if(!root)
            return 0;

        // Current depth =
        // 1 (current node)
        // + maximum depth of
        // left and right subtree
        return 1 + max(
            dfs(root->left),
            dfs(root->right)
        );
    }

    int maxDepth(TreeNode* root) {

        // Return depth of tree
        return dfs(root);
    }
};