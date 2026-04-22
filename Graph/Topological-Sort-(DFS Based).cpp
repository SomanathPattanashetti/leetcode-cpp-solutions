// Problem: Topological Sort (DFS Based)
// Platform: GFG / Standard Graph Problem
// Difficulty: Medium
// Tags: Graph, DFS, Topological Sort, Stack

// ✅ Approach:
// We use DFS (Depth First Search) to perform Topological Sorting.
//
// Key Idea:
// In a Directed Acyclic Graph (DAG), a node should appear
// before all nodes it points to.
//
// So:
// 1. Traverse the graph using DFS
// 2. Visit all children first
// 3. Then push the current node into the stack
//
// Why stack?
// Because the node that finishes last should come first in topo order.
//
// Final step:
// Pop all elements from the stack → gives Topological Order

class Solution
{
	public:
	
	// 🔹 DFS function to process each node
	void DFS(vector<int> adj[], int u, vector<bool>& visited, stack<int>& st) {
	    
	    // Mark current node as visited
	    visited[u] = true;
	    
	    // 🔹 Visit all adjacent (neighbor) nodes first
	    for(int &v : adj[u]) {
	        if(!visited[v])
	            DFS(adj, v, visited, st);
	    }
	    
	    // 🔹 After visiting all children, push current node to stack
	    // (Post-order processing)
	    st.push(u);
	}
	
	// Function to return vertices in Topological order
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> visited(V, false);  // Track visited nodes
	    stack<int> st;                  // Stack to store topo order
	    
	    // 🔹 Call DFS for every unvisited node
	    // (Handles disconnected components as well)
	    for(int i = 0; i < V; i++) {
	        if(!visited[i])
	            DFS(adj, i, visited, st);
	    }
	    
	    vector<int> result;
	    
	    // 🔹 Pop elements from stack to get topo order
	    while(!st.empty()) {
	        result.push_back(st.top());
	        st.pop();
	    }
	    
	    return result;
	}
};