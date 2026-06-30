/*
    LeetCode 98: Validate Binary Search Tree

    Topic: Tree, Binary Search Tree (BST), DFS, Inorder Traversal

    Difficulty: Medium

    Tags:
    Binary Tree,
    Binary Search Tree (BST),
    Depth First Search (DFS),
    Inorder Traversal,
    Recursion

    ✅ Approach:

    A Binary Search Tree (BST)
    has the following property:

    - Every node in the left subtree
      is smaller than the current node.

    - Every node in the right subtree
      is greater than the current node.

    One important property of a BST is:

    Performing an inorder traversal
    (Left → Root → Right)
    always produces nodes
    in strictly increasing order.

    Idea:

    1. Perform inorder traversal
       and store all node values
       in a vector.

    2. Traverse the vector.

    3. If any adjacent elements
       are not strictly increasing
       (current >= next),
       then it is NOT a BST.

    4. Otherwise,
       it is a valid BST.

    Recursive Formula:

        inorder(node)

            inorder(left)

            store node value

            inorder(right)

    Base Case:

    If current node is NULL,
    simply return.

    Why it works:

    - Inorder traversal of a BST
      always visits nodes
      in sorted order.

    - If even one element
      violates the increasing order,
      then BST property
      is violated.

    - Therefore checking whether
      the inorder sequence
      is strictly increasing
      is sufficient.

    Example 1:

            2
           / \
          1   3

    Inorder Traversal:

        [1, 2, 3]

    Since

        1 < 2 < 3

    Output:

        true

    ------------------------------------------------

    Example 2:

            5
           / \
          1   4
             / \
            3   6

    Inorder Traversal:

        [1, 5, 3, 4, 6]

    Here

        5 >= 3

    which breaks the
    increasing order.

    Output:

        false

    ------------------------------------------------

    DFS Flow:

        inorder(5)
        ├── inorder(1)
        │      store 1
        │
        ├── store 5
        │
        └── inorder(4)
               ├── store 3
               ├── store 4
               └── store 6

    Result Vector:

        [1, 5, 3, 4, 6]

    Compare Adjacent Elements:

        1 < 5   ✓

        5 < 3   ✗

    Therefore:

        Not a BST

    Time Complexity:

    O(N)

    Every node is visited
    exactly once.

    Checking the vector
    also takes O(N).

    Space Complexity:

    O(N)

    For storing the inorder
    traversal in the vector.

    Additional recursion stack:

    O(H)

    where

    H = Height of tree.

    Worst Case:

    O(N) recursion stack
    for a skewed tree.
*/

class Solution {
public:

    // Perform inorder traversal
    void inOrder(
        TreeNode* root,
        vector<int>& result
    ){

        // Base case
        if(!root)
            return;

        // Visit left subtree
        inOrder(root->left, result);

        // Store current node
        result.push_back(root->val);

        // Visit right subtree
        inOrder(root->right, result);
    }

    bool isValidBST(TreeNode* root) {

        // Stores inorder traversal
        vector<int> result;

        // Generate inorder sequence
        inOrder(root, result);

        int n = result.size();

        // Check if sequence
        // is strictly increasing
        for(int i = 0; i < n - 1; i++){

            if(result[i] >= result[i + 1])
                return false;
        }

        return true;
    }
};