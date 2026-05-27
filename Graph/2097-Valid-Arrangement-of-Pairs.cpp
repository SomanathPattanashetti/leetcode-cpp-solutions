/*
    LeetCode Problem: 2097. Valid Arrangement of Pairs
    Topic: Euler Path / Hierholzer’s Algorithm

    Difficulty: Hard

    Tags:
    Graph, DFS, Euler Path, Stack

    ✅ Approach:
    This solution uses Hierholzer’s Algorithm
    to find a valid Eulerian Path in a directed graph.

    Goal:
    Arrange all pairs such that:
    end of previous pair == start of next pair

    This is exactly an Euler Path problem where:
    - Each pair represents a directed edge
    - We must use every edge exactly once

    Euler Path Conditions:
    1. One node may have:
         outDegree - inDegree = 1
         -> starting node

    2. One node may have:
         inDegree - outDegree = 1
         -> ending node

    3. All other nodes:
         inDegree == outDegree

    Idea:
    Use DFS traversal with stack.
    Keep removing edges while traversing.
    When no more outgoing edges exist,
    add node to Euler Path.

    Steps:
    1. Build adjacency list.
    2. Calculate indegree and outdegree.
    3. Find starting node:
         - node having outDegree - inDegree == 1
         - otherwise start from first pair node
    4. Perform Hierholzer DFS using stack.
    5. Build Euler Path in reverse order.
    6. Reverse the path.
    7. Convert nodes into edge pairs.

    Time Complexity:
    O(E)

    Space Complexity:
    O(V + E)
*/

class Solution {
public:

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {

        // Adjacency List:
        // u -> v
        unordered_map<int, vector<int>> adj;

        // Store indegree and outdegree
        unordered_map<int, int> inDegree, outDegree;

        // Build graph
        for(auto& pair : pairs){

            int u = pair[0];
            int v = pair[1];

            adj[u].push_back(v);

            inDegree[v]++;
            outDegree[u]++;
        }

        // Default starting node
        int start_node = pairs[0][0];

        // Find Euler Path starting node
        // outDegree - inDegree == 1
        for(auto& [node, neighbors] : adj){

            if(outDegree[node] - inDegree[node] == 1){
                start_node = node;
                break;
            }
        }

        // Store Euler Path
        vector<int> EulerPath;

        // Stack used for iterative DFS
        stack<int> st;

        st.push(start_node);

        while(!st.empty()) {

            int curr = st.top();

            // If outgoing edge exists
            if(!adj[curr].empty()) {

                // Take one neighbor
                int ngbr = adj[curr].back();

                // Remove used edge
                adj[curr].pop_back();

                // Move to next node
                st.push(ngbr);

            } else {

                // No more edges
                // Add node to Euler Path
                EulerPath.push_back(curr);

                st.pop();
            }
        }

        // Reverse because path was built backwards
        reverse(begin(EulerPath), end(EulerPath));

        // Build final answer using consecutive nodes
        vector<vector<int>> result;

        for(int i = 0; i < EulerPath.size()-1; i++) {

            result.push_back({EulerPath[i], EulerPath[i+1]});
        }

        return result;
    }
};