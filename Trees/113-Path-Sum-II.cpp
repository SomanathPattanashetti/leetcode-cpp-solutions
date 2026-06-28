/*
    LeetCode 113: Path Sum II

    Topic: Tree, DFS, Backtracking, Recursion

    Difficulty: Medium

    Tags:
    Binary Tree,
    Depth First Search (DFS),
    Backtracking,
    Recursion

    ✅ Approach:

    We need to find all root-to-leaf paths
    whose sum of node values equals targetSum.

    Unlike Path Sum (112),
    here we must return every valid path,
    not just check whether one exists.

    Idea:

    Use DFS traversal.

    During traversal:

    1. Keep track of the current path
       using a temporary vector.

    2. Keep track of the running sum.

    3. Add the current node value
       to both path and sum.

    4. When a leaf node is reached:

       - If sum equals targetSum,
         store the current path
         in the answer.

    5. Continue DFS for left
       and right subtrees.

    Recursive Formula:

        fillPath(node, targetSum,
                 currentSum, path)

        currentSum += node->val

        path.push_back(node->val)

        if leaf node:

            if currentSum == targetSum
                store path

        fillPath(left)

        fillPath(right)

    Base Case:

    If current node is NULL,
    simply return.

    Why it works:

    - DFS explores every
      root-to-leaf path.

    - The path vector stores
      nodes encountered so far.

    - Whenever a leaf node is reached,
      we verify whether the path sum
      equals targetSum.

    - If yes, we save that path.

    - Since every root-to-leaf path
      is visited exactly once,
      all valid paths are found.

    Example:

             5
            / \
           4   8
          /   / \
         11  13  4
        /  \    / \
       7    2  5   1

    targetSum = 22

    Root-to-Leaf Paths:

    1) 5 → 4 → 11 → 7
       Sum = 27

    2) 5 → 4 → 11 → 2
       Sum = 22  ✅

    3) 5 → 8 → 13
       Sum = 26

    4) 5 → 8 → 4 → 5
       Sum = 22  ✅

    5) 5 → 8 → 4 → 1
       Sum = 18

    Output:

    [
      [5,4,11,2],
      [5,8,4,5]
    ]

    DFS Flow:

        fillPath(5)
        ├── fillPath(4)
        │   └── fillPath(11)
        │       ├── fillPath(7)
        │       │   sum = 27
        │       │   discard
        │       │
        │       └── fillPath(2)
        │           sum = 22
        │           store path
        │
        └── fillPath(8)
            ├── fillPath(13)
            │   sum = 26
            │
            └── fillPath(4)
                ├── fillPath(5)
                │   sum = 22
                │   store path
                │
                └── fillPath(1)

    Final Answer:

    [
      [5,4,11,2],
      [5,8,4,5]
    ]

    Time Complexity:

    O(N * H)

    N = Number of nodes
    H = Height of tree

    Every node is visited once.

    For each valid path,
    copying the path takes O(H).

    Worst Case:

    O(N²) for skewed trees.

    Space Complexity:

    O(H)

    Due to recursion stack.

    Additional Space:

    O(H) for storing
    the current path.

    Output storage is not included
    in auxiliary space complexity.
*/

class Solution {
public:

    void fillPath(
        TreeNode* root,
        int targetSum,
        int sum,
        vector<int> temp,
        vector<vector<int>>& result
    ){

        // Reached beyond leaf
        if(!root)
            return;

        // Include current node
        sum += root->val;

        // Add node to current path
        temp.push_back(root->val);

        // If leaf node reached
        if(root->left == NULL &&
           root->right == NULL){

            // Valid path found
            if(sum == targetSum){

                result.push_back(temp);
                return;
            }

            return;
        }

        // Explore left subtree
        fillPath(
            root->left,
            targetSum,
            sum,
            temp,
            result
        );

        // Explore right subtree
        fillPath(
            root->right,
            targetSum,
            sum,
            temp,
            result
        );
    }

    vector<vector<int>> pathSum(
        TreeNode* root,
        int targetSum
    ) {

        vector<vector<int>> result;

        // Stores current path
        vector<int> temp;

        // Running sum
        int sum = 0;

        // Start DFS
        fillPath(
            root,
            targetSum,
            sum,
            temp,
            result
        );

        return result;
    }
};