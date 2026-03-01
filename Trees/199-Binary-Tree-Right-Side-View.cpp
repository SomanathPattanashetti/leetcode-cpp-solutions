// Leetcode Problem: 199. Binary Tree Right Side View
// Link: https://leetcode.com/problems/binary-tree-right-side-view/
// Difficulty: Medium
// Tags: Tree, Breadth-First Search (BFS), Binary Tree

// ✅ Approach:
// Use Level Order Traversal (BFS).
// At each level of the tree, the last node we process
// will be the rightmost node visible from the right side.
//
// Steps:
// 1. Use a queue to perform level order traversal.
// 2. For each level:
//      - Traverse all nodes of that level.
//      - Keep updating a pointer (rightNode) to the current node.
//      - After finishing the level, rightNode will store
//        the last node of that level (rightmost node).
// 3. Add rightNode->val to the result.

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        // If tree is empty, return empty result
        if(!root)
            return {};
        
        queue<TreeNode*> que;   // Queue for BFS traversal
        vector<int> result;     // Stores right side view values
        
        que.push(root);         // Start with root node
        
        // Perform level order traversal
        while(!que.empty()) {

            int n = que.size();          // Number of nodes at current level
            TreeNode* rightNode = NULL;  // Will store last node of this level
            
            // Traverse all nodes of current level
            while(n--) {

                rightNode = que.front(); // Get current node
                que.pop();               // Remove from queue
                
                // Push left child (if exists)
                if(rightNode->left)
                    que.push(rightNode->left);
                
                // Push right child (if exists)
                if(rightNode->right)
                    que.push(rightNode->right);
            }

            // After finishing this level,
            // rightNode will be the rightmost node
            result.push_back(rightNode->val);
        }

        return result;   // Return final right side view
    }
};