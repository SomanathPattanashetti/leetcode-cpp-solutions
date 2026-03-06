// Leetcode Problem: 543. Diameter of Binary Tree
// Link: https://leetcode.com/problems/diameter-of-binary-tree/
// Difficulty: Easy
// Tags: Tree, Depth First Search, Binary Tree

// Definition for a binary tree node.
/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/

// ✅ Approach:
// The diameter of a binary tree is the length of the longest path
// between any two nodes in the tree.
//
// The path may or may not pass through the root.
//
// Idea:
// For every node:
//   Diameter through that node = height(left subtree) + height(right subtree)
//
// We compute the height of the tree using DFS recursion.
// While calculating the height, we keep updating the maximum diameter.

class Solution {
public:
    int maxDiameter = 0; // Stores the maximum diameter found

    // Function to return the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        getHeight(root);   // Calculate heights and update diameter
        return maxDiameter;
    }

    // Recursive function to compute the height of the tree
    int getHeight(TreeNode* root) {

        // Base Case:
        // If node is NULL, height is 0
        if(root == NULL)
            return 0;

        // 🔹 Get height of left subtree
        int leftHeight = getHeight(root->left);

        // 🔹 Get height of right subtree
        int rightHeight = getHeight(root->right);

        // 🔹 Diameter passing through this node
        int currentDiameter = leftHeight + rightHeight;

        // Update the maximum diameter found so far
        maxDiameter = max(maxDiameter, currentDiameter);

        // Return height of current node
        // Height = 1 + max(left subtree height, right subtree height)
        return 1 + max(leftHeight, rightHeight);
    }
};