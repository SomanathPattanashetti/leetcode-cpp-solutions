// Problem: Disjoint Set (Union-Find)
// Platform: GeeksforGeeks
// Difficulty: Easy
// Tags: Graph, DSU, Union-Find, Path Compression

// ✅ Approach:
// We use Disjoint Set Union (DSU) to efficiently manage groups of elements.
//
// There are two main operations:
// 1. find(x)  -> Finds the representative (parent) of element x
// 2. union(x, z) -> Merges the sets containing x and z
//
// 🔹 Path Compression Optimization:
// While finding the parent, we directly connect nodes to the root
// to make future queries faster.
//
// 🔹 Query Types:
// Type 1: [1, x, z] → Perform UNION of x and z
// Type 2: [2, x]    → Find representative of x

class Solution {
  public:
  
    // 🔹 Find function with Path Compression
    int find(int element, vector<int>& parent){
        
        // Base Case: if element is its own parent, return it
        if(element == parent[element])    
            return element;
            
        // Path Compression: directly attach to root
        return parent[element] = find(parent[element], parent);
    }
    
    vector<int> DSU(int n, vector<vector<int>>& queries) {
        
        // 🔹 Initialize parent array
        // Each element is its own parent initially
        vector<int> parent(n+1, 0);
        for(int i = 1; i <= n; i++)
            parent[i] = i;
            
        // 🔹 To store results of Type 2 queries
        vector<int> result;
        
        // 🔹 Process each query
        for(auto& query : queries){
            
            // 🔹 Type 1: UNION operation
            if(query[0] == 1){
                
                int x = query[1];
                int z = query[2];
                
                // Find parents (representatives)
                int parent_x = find(x, parent);
                int parent_z = find(z, parent);
                
                // If different sets, merge them
                if(parent_x != parent_z)
                    parent[parent_x] = parent_z;
            
            // 🔹 Type 2: FIND operation
            } else {
                
                int x = query[1];
                
                // Store representative of x
                result.push_back(find(x, parent));
            }
        }
        
        return result;
    }
};