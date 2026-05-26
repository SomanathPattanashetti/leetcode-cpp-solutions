/*
    GFG Problem: Euler Circuit and Euler Path
    Topic: Graph Theory, DFS

    Difficulty: Medium

    Tags:
    Graph, DFS, Euler Path, Euler Circuit

    ✅ Approach:
    This solution checks whether an undirected graph contains:

    0 -> Not Eulerian
    1 -> Euler Path (Semi-Eulerian)
    2 -> Euler Circuit (Eulerian)

    Important Concepts:

    Euler Path:
    A path that visits every edge exactly once.

    Euler Circuit:
    A cycle that visits every edge exactly once
    and comes back to the starting node.

    Conditions:

    1. Graph must be connected
       (ignore isolated vertices having degree 0)

    2. If all vertices have even degree:
           Euler Circuit exists

    3. If exactly 2 vertices have odd degree:
           Euler Path exists

    4. If more than 2 odd degree vertices:
           Not Eulerian

    ✅ Steps:
    1. Find a vertex having non-zero degree.
    2. Perform DFS traversal from that node.
    3. Check whether all non-zero degree vertices
       are visited or not.
    4. Count vertices having odd degree.
    5. Return answer based on odd degree count.

    Return Values:
    0 -> No Euler Path/Circuit
    1 -> Euler Path exists
    2 -> Euler Circuit exists

    Time Complexity:
    O(V + E)

    Space Complexity:
    O(V)
*/

class Solution {
  public:
  
    // DFS Traversal
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited){
        
        // Mark current node visited
        visited[u] = true;
        
        // Traverse all adjacent vertices
        for(auto& v : adj[u]){
            
            // Visit unvisited nodes
            if(!visited[v]){
                dfs(v, adj, visited);
            }
        }
    }
  
    // Function to check graph connectivity
    bool isConnected(int V, vector<vector<int>>& adj){
        
        // Find first non-zero degree vertex
        int non_zero_vertex = -1;
        
        for(int i = 0; i < V; i++){
            
            // Vertex having edges
            if(adj[i].size() != 0){
                non_zero_vertex = i;
                break;
            }
        }
        
        // Visited array
        vector<bool> visited(V, false);
        
        // Perform DFS from non-zero degree vertex
        dfs(non_zero_vertex, adj, visited);
        
        // Check all non-zero degree vertices visited or not
        for(int i = 0; i < V; i++){
            
            if(!visited[i] && adj[i].size() != 0)
                return false;
        }
        
        return true;
    }
    
    int isEulerCircuit(int V, vector<vector<int>>& adj) {
        
        // Step 1:
        // Graph must be connected
        if(!isConnected(V, adj))
            return 0;
            
        int odd_degree = 0;
        
        // Step 2:
        // Count odd degree vertices
        for(int i = 0; i < V; i++){
            
            if(adj[i].size() % 2 != 0){
                odd_degree++;
            }
        }
        
        // Step 3:
        // Decide answer based on odd degree count
        
        // More than 2 odd degree vertices
        // => Not Eulerian
        if(odd_degree > 2)
            return 0;
            
        // Exactly 2 odd degree vertices
        // => Euler Path exists
        else if(odd_degree == 2)
            return 1;
            
        // All even degree vertices
        // => Euler Circuit exists
        else
            return 2;
    }
};