// Problem: Topological Sort (BFS Based - Kahn's Algorithm)
// Platform: GFG / Standard Graph Problem
// Difficulty: Medium
// Tags: Graph, BFS, Topological Sort, Queue, Indegree

// ✅ Approach:
// We use BFS (Kahn’s Algorithm) to perform Topological Sorting.
//
// Key Idea:
// A node can be processed only when its indegree = 0
// (i.e., no incoming edges → no dependencies).
//
// So:
// 1. Calculate indegree of each node
// 2. Push all nodes with indegree = 0 into a queue
// 3. Process nodes one by one (BFS style)
// 4. For each processed node, reduce indegree of its neighbors
// 5. If any neighbor's indegree becomes 0, push it into queue
//
// Why queue?
// Because we process nodes level by level (like BFS),
// starting from nodes with no dependencies.
//
// Final step:
// The order in which nodes are processed → Topological Order

class Solution
{
	public:
	
	// Function to return vertices in Topological order
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V, 0);  // Store indegree of each node
	    
	    // 🔹 Step 1: Calculate indegree
	    for(int i = 0; i < V; i++) {
	        for(int &v : adj[i]) {
	            indegree[v]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    // 🔹 Step 2: Push nodes with indegree = 0
	    for(int i = 0; i < V; i++) {
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    
	    vector<int> result;
	    
	    // 🔹 Step 3: Process nodes using BFS
	    while(!q.empty()) {
	        int u = q.front();
	        q.pop();
	        
	        result.push_back(u);  // Add to topo order
	        
	        // 🔹 Step 4: Reduce indegree of neighbors
	        for(int &v : adj[u]) {
	            indegree[v]--;
	            
	            // 🔹 Step 5: If indegree becomes 0, push to queue
	            if(indegree[v] == 0)
	                q.push(v);
	        }
	    }
	    
	    return result;
	}
};