/*
    LeetCode 797: All Paths From Source to Target
    Topic: Graph, DFS, Backtracking

    Difficulty: Medium

    Tags:
    Graph, Depth First Search (DFS),
    Backtracking

    ✅ Approach:

    This solution uses DFS with
    backtracking to generate all
    possible paths from source node
    (0) to target node (n - 1).

    Observation:

    The graph is a Directed Acyclic
    Graph (DAG).

    We need to find every possible
    path from node 0 to node n - 1.

    Idea:

    Start DFS from source node.

    While traversing:

    - Add current node to path.
    - If target is reached,
      store the current path.
    - Otherwise explore all
      neighboring nodes.
    - After exploration,
      remove current node from path
      (Backtracking).

    Backtracking is important because:

    - One path may share nodes with
      another path.
    - After completing one path,
      we must remove the current node
      before exploring a different path.

    Cases:

    1. Add current node to path.

    2. If current node is target:
       - Store the path in result.

    3. Otherwise:
       - Visit all neighbors using DFS.

    4. Remove current node from path
       before returning.

    Why it works:

    - DFS explores every possible path.

    - Whenever target is reached,
      the current path represents
      one valid answer.

    - Backtracking ensures the path
      vector always contains nodes
      belonging to the current DFS path.

    Example:

        Graph:

        0 -> 1 -> 3
         \       ^
          \     /
           -> 2

        Paths:

        [0,1,3]
        [0,2,3]

    Output:

        [[0,1,3],
         [0,2,3]]

    Time Complexity:

    O(2^N * N)

    -> Number of paths in a DAG can
       be exponential.

    -> Copying each path takes O(N).

    Space Complexity:

    O(N)

    -> Recursive DFS stack
    -> Current path vector

    (Result storage excluded)
*/

class Solution {
public:

    void getAllPath(vector<vector<int>>& adj,
                    int u,
                    int target,
                    vector<vector<int>>& result,
                    vector<int>& temp) {

        // Add current node to path
        temp.push_back(u);

        // Reached destination
        if(u == target) {

            // Store current path
            result.push_back(temp);
        }
        else {

            // Explore all neighbors
            for(auto& v : adj[u]) {

                getAllPath(adj,
                           v,
                           target,
                           result,
                           temp);
            }
        }

        // Backtrack
        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(
        vector<vector<int>>& graph) {

        int n = graph.size();

        vector<vector<int>> result;
        vector<int> temp;

        int source = 0;
        int target = n - 1;

        // Find all paths
        getAllPath(graph,
                   source,
                   target,
                   result,
                   temp);

        return result;
    }
};