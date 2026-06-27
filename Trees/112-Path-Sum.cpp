/*
    LeetCode 112: Path Sum

    Topic: Tree, DFS, Recursion

    Difficulty: Easy

    Tags:
    Binary Tree,
    Depth First Search (DFS),
    Recursion

    ✅ Approach:

    We need to determine whether there exists
    a root-to-leaf path such that the sum
    of all node values equals targetSum.

    Idea:

    Traverse the tree using DFS.

    At every node:

    1. Subtract the current node's value
       from targetSum.

    2. Continue searching in both
       left and right subtrees.

    3. When a leaf node is reached,
       check whether the remaining
       targetSum becomes 0.

    If yes, a valid path exists.

    Recursive Formula:

        solve(node, target)

        target = target - node->val

        return

        solve(left, target)
            ||
        solve(right, target)

    Base Cases:

    1. If current node is NULL,
       return false.

    2. If current node is a leaf,
       return (remaining target == 0).

    Why it works:

    - Every recursive call carries
      the remaining sum needed.

    - Once we reach a leaf,
      if the remaining sum is 0,
      then the path exactly matches
      the target.

    - Otherwise that path is invalid.

    Example:

             5
            / \
           4   8
          /   / \
         11  13  4
        /  \      \
       7    2      1

    targetSum = 22

    Path:

        5 → 4 → 11 → 2

    Remaining Sum:

        22
        ↓

        22 - 5 = 17
        17 - 4 = 13
        13 -11 = 2
         2 - 2 = 0

    Reached leaf with
    remaining sum = 0.

    Output:

        true

    DFS Flow:

        solve(5,22)
        ├── solve(4,17)
        │   └── solve(11,13)
        │       ├── solve(7,2)
        │       │   return false
        │       │
        │       └── solve(2,2)
        │           return true
        │
        └── solve(8,17)

    Since one path returns true,
    the final answer is true.

    Example (No Valid Path):

          1
         / \
        2   3

    targetSum = 5

    Paths:

        1 → 2 = 3

        1 → 3 = 4

    Neither equals 5.

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

    bool solve(TreeNode* root, int targetSum){

        // Reached beyond a leaf
        // No valid path
        if(!root)
            return false;

        // Subtract current node's value
        // from remaining target
        targetSum -= root->val;

        // If current node is a leaf,
        // check whether target becomes 0
        if(root->left == NULL && root->right == NULL){

            if(targetSum == 0)
                return true;

            return false;
        }

        // Search in left subtree
        bool leftSide = solve(
            root->left,
            targetSum
        );

        // Search in right subtree
        bool rightSide = solve(
            root->right,
            targetSum
        );

        // If either subtree has
        // a valid path, return true
        return leftSide || rightSide;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        // Start DFS from root
        return solve(
            root,
            targetSum
        );
    }
};