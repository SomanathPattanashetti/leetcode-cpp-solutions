/*
    LeetCode 1443: Minimum Time to Collect All Apples in a Tree

    Topic:
    Tree, Graph, DFS

    Difficulty:
    Medium

    Tags:
    Tree,
    Depth First Search (DFS),
    Graph

    ✅ Approach:

    This solution uses DFS to calculate
    the minimum time required to collect
    all apples in the tree and return
    back to the root whenever necessary.

    Observation:

    - The given graph is a Tree.
    - Each edge takes 1 second to travel.
    - Moving from parent to child and
      coming back costs 2 seconds.
    - We should visit only those
      subtrees that contain at least
      one apple.

    Idea:

    Start DFS from root node (0).

    For every child:

    - Recursively calculate time needed
      to collect apples in that child's
      subtree.

    - If the subtree contains apples
      (or the child itself has an apple),
      add:

            2 + childSubtreeTime

      because:

      - 1 second to go to child
      - 1 second to come back
      - childSubtreeTime for collecting
        apples inside that subtree

    Cases:

    1. Visit every child node.

    2. Ignore parent node to avoid
       revisiting the same edge.

    3. Compute time required from
       each child subtree.

    4. If child subtree contains
       apples:

       totalTime +=
       2 + childSubtreeTime

    5. Return total time collected
       from all valid subtrees.

    Why it works:

    - DFS explores every subtree exactly once.

    - Only subtrees containing apples
      contribute to the answer.

    - Unnecessary branches are skipped,
      minimizing travel time.

    Example:

            0
          /   \
         1     2
              / \
             3   4

    Apples at nodes:
    [false, false, true, false, true]

    Traversal:

    0 -> 2 -> 4 -> 2 -> 0

    Time:

    Edge (0,2) : 2
    Edge (2,4) : 2

    Total = 4

    Time Complexity:

    O(V + E)

    - Every node is visited once.
    - Every edge is processed once.

    Space Complexity:

    O(V)

    - DFS recursion stack.
    - Adjacency list excluded.
*/

class Solution {
public:

    int dfs(unordered_map<int, vector<int>>& adj,
            int currentNode,
            int parentNode,
            vector<bool>& hasApple) {

        int totalTime = 0;

        for (int childNode : adj[currentNode]) {

            // Skip parent node
            if (childNode == parentNode)
                continue;

            int childSubtreeTime =
                dfs(adj,
                    childNode,
                    currentNode,
                    hasApple);

            // If child's subtree contains
            // an apple, include travel cost
            if (childSubtreeTime > 0 ||
                hasApple[childNode]) {

                totalTime +=
                    2 + childSubtreeTime;
            }
        }

        return totalTime;
    }

    int minTime(int n,
                vector<vector<int>>& edges,
                vector<bool>& hasApple) {

        unordered_map<int, vector<int>> adj;

        // Build adjacency list
        for (auto& edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(adj,
                   0,
                   -1,
                   hasApple);
    }
};