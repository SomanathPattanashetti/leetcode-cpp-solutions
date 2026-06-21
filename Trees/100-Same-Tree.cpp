/*
    LeetCode 100: Same Tree

    Topic: Tree, DFS, Recursion

    Difficulty: Easy

    Tags:
    Binary Tree,
    Depth First Search (DFS),
    Recursion

    ✅ Approach:

    Two binary trees are considered
    the same if:

    1. Their structure is identical.

    2. Corresponding nodes contain
       the same values.

    Idea:

    For every pair of nodes (p, q):

    1. If both nodes are NULL,
       they are identical.

    2. If one node is NULL and
       the other is not,
       trees are different.

    3. If node values are different,
       trees are different.

    4. Recursively compare:

       - Left subtree of p and q

       - Right subtree of p and q

    Recursive Formula:

        isSameTree(p, q) =

        (p->val == q->val)

        AND

        isSameTree(
            p->left,
            q->left
        )

        AND

        isSameTree(
            p->right,
            q->right
        )

    Base Cases:

    1. If both nodes are NULL,
       return true.

    2. If only one node is NULL,
       return false.

    Why it works:

    - DFS visits corresponding nodes
      in both trees simultaneously.

    - Every recursive call checks:

        a) Structure match

        b) Value match

    - If any mismatch is found,
      recursion immediately returns false.

    - Trees are same only when
      all corresponding nodes match.

    Example:

            Tree 1                Tree 2

               1                     1
              / \                   / \
             2   3                 2   3

    Comparison:

        Node 1 == Node 1 ✓

        Node 2 == Node 2 ✓

        Node 3 == Node 3 ✓

        All NULL children match ✓

    Output:

        true

    DFS Flow:

        isSameTree(1,1)
        │
        ├── isSameTree(2,2)
        │   ├── isSameTree(NULL,NULL)
        │   │   return true
        │   │
        │   └── isSameTree(NULL,NULL)
        │       return true
        │
        │   return true
        │
        └── isSameTree(3,3)
            ├── isSameTree(NULL,NULL)
            │   return true
            │
            └── isSameTree(NULL,NULL)
                return true

            return true

        return true

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

    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Base Case:
        // Both nodes are NULL,
        // so they are identical
        if(!p && !q)
            return true;

        // One node exists and
        // the other doesn't
        if(!p || !q)
            return false;

        // Current node values
        // must match
        if(p->val != q->val)
            return false;

        // Compare left subtree
        bool leftSame =
            isSameTree(
                p->left,
                q->left
            );

        // Compare right subtree
        bool rightSame =
            isSameTree(
                p->right,
                q->right
            );

        // Both subtrees must match
        return leftSame && rightSame;
    }
};