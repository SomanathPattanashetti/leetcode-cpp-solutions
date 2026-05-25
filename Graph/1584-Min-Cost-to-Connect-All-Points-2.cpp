/*
    LeetCode 1584: Min Cost to Connect All Points
    Topic: Minimum Spanning Tree (Kruskal’s Algorithm)

    Difficulty: Medium

    Tags:
    Graph, MST, Kruskal's Algorithm,
    Union Find, DSU, Greedy

    ✅ Approach:
    This solution uses Kruskal’s Algorithm
    to find the Minimum Spanning Tree (MST).

    Each point acts like a graph node.

    Cost between two points:
    Manhattan Distance

    Formula:
    |x1 - x2| + |y1 - y2|

    Goal:
    Connect all points with minimum total cost
    without forming cycles.

    Idea:
    1. Create all possible edges between points.
    2. Store:
         {u, v, weight}
    3. Sort edges by weight.
    4. Pick smallest edge first.
    5. Use DSU (Disjoint Set Union)
       to detect cycles.
    6. If two nodes belong to different sets:
         - Connect them
         - Add edge weight to answer
    7. Continue until all nodes are connected.

    DSU Optimizations Used:
    1. Path Compression
    2. Union By Rank

    Time Complexity:
    Building All Edges:
    O(V²)

    Sorting Edges:
    O(E log E)

    Since:
    E = V²

    Total:
    O(V² log V)

    Space Complexity:
    O(V²)
*/

class Solution {
public:

    // Parent array:
    // Stores representative(parent) of each node
    vector<int> parent;

    // Rank array:
    // Helps keep tree balanced
    vector<int> rank;

    // Find ultimate parent
    // Using Path Compression
    int find(int i){

        // If node is its own parent
        if(i == parent[i])
            return i;

        // Path Compression
        return parent[i] = find(parent[i]);
    }

    // Union By Rank
    void Union(int u, int v){

        int parent_u = find(u);
        int parent_v = find(v);

        // Already in same component
        if(parent_u == parent_v)
            return;

        // Attach smaller rank tree
        // under larger rank tree
        if(rank[parent_u] > rank[parent_v]){

            parent[parent_v] = parent_u;

        }else if(rank[parent_v] > rank[parent_u]){

            parent[parent_u] = parent_v;

        }else{

            // If ranks are same,
            // connect any one
            parent[parent_u] = parent_v;

            // Increase rank
            rank[parent_v]++;
        }
    }

    // Kruskal's Algorithm
    int kruskals(vector<vector<int>>& vec, int V){

        int sum = 0;

        // Traverse all sorted edges
        for(auto& temp : vec){

            int u = temp[0];
            int v = temp[1];
            int w = temp[2];

            int parent_u = find(u);
            int parent_v = find(v);

            // If no cycle forms
            if(parent_u != parent_v){

                // Connect components
                Union(u, v);

                // Add edge weight
                sum += w;
            }
        }

        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {

        int V = points.size();

        // Initialize DSU
        parent.resize(V);

        // Initially all ranks are 0
        rank.resize(V, 0);

        // Every node is its own parent initially
        for(int i = 0; i < V; i++)
            parent[i] = i;

        // Stores:
        // {u, v, weight}
        vector<vector<int>> vec;

        // Create all possible edges
        for(int i = 0; i < V; i++){

            for(int j = i + 1; j < V; j++){

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                // Manhattan Distance
                int d = abs(x1 - x2) + abs(y1 - y2);

                // Store edge
                vec.push_back({i, j, d});
            }
        }

        // Sort edges based on weight
        sort(begin(vec), end(vec),
            [&](auto& vec1, auto& vec2){

                return vec1[2] < vec2[2];
            });

        // Apply Kruskal's Algorithm
        return kruskals(vec, V);
    }
};