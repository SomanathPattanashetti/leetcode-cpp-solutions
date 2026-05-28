/*
    LeetCode Problem: 3203. Find Minimum Diameter After Merging Two Trees
    Topic: Tree Diameter / BFS

    Difficulty: Hard

    Tags:
    Tree, Graph, BFS, Diameter

    ✅ Approach:
    This solution finds the diameter of both trees
    using BFS and then calculates the minimum
    possible diameter after connecting them.

    Goal:
    Connect one node from Tree-1 and one node
    from Tree-2 such that the final diameter
    becomes minimum.

    Important Concept:
    To minimize diameter,
    connect the centers of both trees.

    Formula:
    New Diameter =
    max(
        d1,
        d2,
        ceil(d1/2) + ceil(d2/2) + 1
    )

    where:
    d1 = diameter of first tree
    d2 = diameter of second tree

    ------------------------------------------------

    Diameter of Tree:
    Longest distance between any two nodes.

    How to find diameter using BFS?

    Step-1:
    Start BFS from any node.
    Find the farthest node.

    Step-2:
    Start BFS again from that farthest node.
    The maximum distance obtained is diameter.

    Why does this work?
    Because in a tree:
    - One endpoint of diameter is always the
      farthest node from any random node.

    ------------------------------------------------

    Steps:
    1. Build adjacency list for both trees.
    2. Find diameter of Tree-1.
    3. Find diameter of Tree-2.
    4. Calculate merged diameter.
    5. Return maximum among:
         d1, d2, mergedDiameter

    Time Complexity:
    O(V + E)

    Space Complexity:
    O(V + E)
*/

class Solution {
public:

    /*
        BFS Function

        Returns:
        {farthest_node, distance}

        Used for finding:
        1. Farthest node
        2. Diameter
    */
    pair<int, int> bfs(unordered_map<int, vector<int>>& adj,
                       int source){

        // Track visited nodes
        unordered_map<int, bool> visited;

        // Normal BFS queue
        queue<int> que;

        que.push(source);

        visited[source] = true;

        int farthest_node = source;

        int distance = 0;

        // Standard BFS
        while(!que.empty()){

            int size = que.size();

            // Process one BFS level
            while(size--){

                int current_node = que.front();

                que.pop();

                // Last node processed in level
                // becomes farthest node
                farthest_node = current_node;

                // Traverse neighbors
                for(auto& neighbour : adj[current_node]){

                    if(!visited[neighbour]){

                        visited[neighbour] = true;

                        que.push(neighbour);
                    }
                }
            }

            // Increase distance level
            if(!que.empty())
                distance++;
        }

        return {farthest_node, distance};
    }

    /*
        Find Diameter of Tree

        Two BFS Method:
        1. Find farthest node
        2. BFS again from that node
    */
    int findDiameter(unordered_map<int, vector<int>>& adj){

        // Start BFS from any node
        int start_node = adj.begin()->first;

        // Find one endpoint of diameter
        auto [farthest_node, distance] =
            bfs(adj, start_node);

        // Find actual diameter
        auto [other_end_node, diameter] =
            bfs(adj, farthest_node);

        return diameter;
    }

    /*
        Build Undirected Graph
    */
    unordered_map<int, vector<int>>
    buildAdjList(vector<vector<int>>& edges){

        unordered_map<int, vector<int>> adj;

        for(auto& edge : edges){

            int u = edge[0];
            int v = edge[1];

            // Undirected edge
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {

        // Build both trees
        unordered_map<int, vector<int>> adj1 =
            buildAdjList(edges1);

        unordered_map<int, vector<int>> adj2 =
            buildAdjList(edges2);

        // Diameter of Tree-1
        int d1 = findDiameter(adj1);

        // Diameter of Tree-2
        int d2 = findDiameter(adj2);

        /*
            Minimum possible merged diameter

            ceil(d1/2) -> radius of Tree-1
            ceil(d2/2) -> radius of Tree-2

            +1 for new connecting edge
        */
        int combined =
            (d1 + 1) / 2 +
            (d2 + 1) / 2 + 1;

        // Final answer
        return max({d1, d2, combined});
    }
};