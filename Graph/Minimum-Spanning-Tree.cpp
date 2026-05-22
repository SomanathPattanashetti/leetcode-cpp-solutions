/*
    GFG Problem: Minimum Spanning Tree
    Topic: Prim’s Algorithm

    Difficulty: Medium

    Tags:
    Graph, Minimum Spanning Tree (MST), Greedy, Priority Queue

    ✅ Approach:
    This solution uses Prim’s Algorithm to find the
    Minimum Spanning Tree (MST) of a weighted undirected graph.

    MST means:
    Connect all vertices with minimum total edge weight
    without forming cycles.

    Idea:
    Start from any node (here node 0),
    always pick the minimum weight edge
    that connects a new unvisited node.

    Steps:
    1. Create adjacency list from given edges.
    2. Use a Min Heap (Priority Queue)
       to always get the edge with minimum weight.
    3. Start from node 0 with weight 0.
    4. If node is already visited, skip it.
    5. Otherwise:
         - Add edge weight to answer
         - Mark node as visited
    6. Push all unvisited adjacent nodes
       into the priority queue.
    7. Continue until all nodes are visited.

    Time Complexity:
    O(E log V)

    Space Complexity:
    O(V + E)
*/

class Solution {
  public:
    
    using P = pair<int, int>;
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        // Adjacency List:
        // node -> {adjacent node, weight}
        unordered_map<int, vector<P>> adj;
        
        for(auto& edge : edges){
            
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // Visited array to avoid cycles
        vector<bool> visited(V, false);
        
        int sum = 0;
        
        // Min Heap:
        // {weight, node}
        priority_queue<P, vector<P>, greater<P>> pq;
        
        // Start from node 0
        pq.push({0, 0});
        
        while(!pq.empty()){
            
            auto [wt, node] = pq.top();
            pq.pop();
            
            // Skip if already visited
            if(visited[node])
                continue;
                
            // Add current edge weight to MST sum
            sum += wt;
            
            // Mark node visited
            visited[node] = true;
            
            // Traverse adjacent nodes
            for(auto [adj_node, adj_node_wt] : adj[node]){
                
                // Push only unvisited nodes
                if(!visited[adj_node])
                    pq.push({adj_node_wt, adj_node});
            }
        }
        
        return sum;
    }
};