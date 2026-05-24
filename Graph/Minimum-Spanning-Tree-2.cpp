/*
    GFG Problem: Minimum Spanning Tree
    Topic: Kruskal’s Algorithm

    Difficulty: Medium

    Tags:
    Graph, Minimum Spanning Tree (MST),
    Greedy, Disjoint Set Union (DSU), Union Find

    ✅ Approach:
    This solution uses Kruskal’s Algorithm
    to find the Minimum Spanning Tree (MST)
    of a weighted undirected graph.

    MST means:
    Connect all vertices using minimum total edge weight
    without forming cycles.

    Idea:
    Sort all edges based on weight.
    Always pick the smallest edge
    that does NOT form a cycle.

    To efficiently detect cycles,
    we use Disjoint Set Union (DSU).

    DSU Operations:
    1. Find:
       Finds ultimate parent of a node.
       Uses Path Compression optimization.

    2. Union:
       Connects two components.
       Uses Union by Rank optimization.

    Steps:
    1. Initialize every node as its own parent.
    2. Sort all edges by weight.
    3. Traverse sorted edges one by one.
    4. For each edge:
         - Find parent of both nodes
         - If parents are different:
              -> No cycle
              -> Include edge in MST
              -> Perform Union
         - Otherwise skip edge
    5. Return total MST weight.

    Time Complexity:
    O(E log E)

    Space Complexity:
    O(V)
*/

class Solution {
  public:
    
    // Parent array for DSU
    vector<int> parent;
    
    // Rank array for Union by Rank
    vector<int> rank;
    
    // Find ultimate parent with Path Compression
    int find(int i){
        
        // Node is its own parent
        if(i == parent[i])
            return i;
            
        // Path Compression
        return parent[i] = find(parent[i]);
    }
    
    // Union of two sets
    void Union(int u, int v){
        
        int parent_u = find(u);
        int parent_v = find(v);

        // Both belong to same component
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
            // make one parent of another
            parent[parent_u] = parent_v;
            
            // Increase rank
            rank[parent_v]++;
        }
    }
    
    // Kruskal's Algorithm
    int kruskals(vector<vector<int>>& edges, int V){
        
        int sum = 0;
        
        // Traverse sorted edges
        for(auto& edge : edges){
            
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            // Find parents
            int parent_u = find(u);
            int parent_v = find(v);
            
            // If no cycle formed
            if(parent_u != parent_v){
                
                // Include edge in MST
                Union(u, v);
                
                // Add edge weight
                sum += w;
            }
        }
        
        return sum;
    }
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        // Initialize DSU
        parent.resize(V);
        rank.resize(V, 0);
        
        // Every node is its own parent initially
        for(int i=0; i<V; i++)
            parent[i] = i;
            
        // Sort edges based on weight
        auto comparator = [&](vector<int>& vec1, vector<int>& vec2){
            return vec1[2] < vec2[2];
        };
        
        sort(begin(edges), end(edges), comparator);
        
        // Apply Kruskal's Algorithm
        return kruskals(edges, V);
    }
};