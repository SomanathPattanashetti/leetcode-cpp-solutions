// Leetcode Problem: 199. Binary Tree Right Side View
// Link: https://leetcode.com/problems/binary-tree-right-side-view/
// Difficulty: Medium
// Tags: Tree, Depth-First Search (DFS), Breadth-First Search (BFS)

// ✅ Approach:
// We use Preorder Traversal (Root → Right → Left).
// The idea is to always visit the RIGHT node first,
// because the rightmost node at each level is visible from the right side.
//
// We keep track of the current level.
// If we are visiting a level for the first time,
// we store that node’s value in the result.
//
// Since we go Right first, the first node we see at each level
// will be the rightmost node.

// Definition for a binary tree node.
/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
*/

class Solution {
public:

    // 🔹 Recursive function for Preorder Traversal
    void preOrder(TreeNode* root, int level, vector<int>& result) {

        // Base Case:
        // If node is NULL, return
        if(!root)
            return;

        // If this level is visited for the first time,
        // add the current node value to result
        if(result.size() < level) {
            result.push_back(root->val);
        }

        // 🔹 Visit Right subtree first (important step)
        preOrder(root->right, level + 1, result);

        // 🔹 Then visit Left subtree
        preOrder(root->left, level + 1, result);
    }

    vector<int> rightSideView(TreeNode* root) {

        vector<int> result;  // Stores right side view

        // Start traversal from level 1
        preOrder(root, 1, result);

        return result;  // Contains rightmost node of each level
    }
};