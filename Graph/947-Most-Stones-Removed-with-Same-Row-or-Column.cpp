/*
    LeetCode 947: Most Stones Removed with Same Row or Column
    Topic: Graph, DFS

    Difficulty: Medium

    Tags:
    Graph, Depth First Search (DFS)

    ✅ Approach:
    This solution uses DFS to find
    connected components among stones.

    Observation:
    A stone can be removed if there is
    at least one other stone in the
    same row or same column.

    Stones that are connected through
    rows or columns form a component.

    In every connected component:
    - We can remove all stones except one.
    - If a component contains k stones,
      removable stones = k - 1.

    Therefore:

    Total Stones Removed =
    Total Stones - Number of Components

    Idea:
    Treat every stone as a node.

    Two stones are connected if:
    - They are in the same row, OR
    - They are in the same column

    Use DFS to count the number of
    connected components.

    Cases:

    1. Start DFS from every unvisited stone.

    2. Mark current stone as visited.

    3. Visit all stones sharing
       the same row or column.

    4. One DFS traversal completes
       one connected component.

    5. Count total components.

    6. Answer =
       Total Stones - Components

    Why it works:

    - All stones inside one component
      are connected directly or indirectly.

    - From a component having k stones,
      exactly one stone must remain.

    - Hence removable stones = k - 1.

    - Summing for all components:

      Total Removed =
      Total Stones - Components

    Example:

        Stones:

        [0,0]  [0,1]

        [1,0]

    Connections:
        [0,0] ↔ [0,1]
        [0,0] ↔ [1,0]

    Component Count = 1
    Total Stones = 3

    Answer = 3 - 1 = 2

    Time Complexity:
    O(N²)

    -> For every stone,
       we may compare with all
       other stones.

    Space Complexity:
    O(N)

    -> Visited array
    -> Recursive DFS stack
*/

class Solution {
public:

    void dfs(vector<vector<int>>& stones,
             int index,
             vector<bool>& visited) {

        // Mark current stone visited
        visited[index] = true;

        // Explore all connected stones
        for(int i = 0; i < stones.size(); i++) {

            // Same row OR same column
            if(!visited[i] &&
               (stones[index][0] == stones[i][0] ||
                stones[index][1] == stones[i][1])) {

                dfs(stones, i, visited);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();

        vector<bool> visited(n, false);

        int components = 0;

        // Find all connected components
        for(int i = 0; i < n; i++) {

            if(!visited[i]) {

                dfs(stones, i, visited);

                components++;
            }
        }

        // Remove all stones except
        // one from each component
        return n - components;
    }
};