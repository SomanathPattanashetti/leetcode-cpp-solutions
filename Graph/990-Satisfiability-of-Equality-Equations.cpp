// Leetcode Problem: 990. Satisfiability of Equality Equations
// Link: https://leetcode.com/problems/satisfiability-of-equality-equations/
// Difficulty: Medium
// Tags: Graph, Union-Find (Disjoint Set), String

// ✅ Approach:
// We use Disjoint Set (Union-Find) to group variables that are equal.
//
// Step 1: Initialize each variable ('a' to 'z') as its own parent.
// Step 2: First process all "==" equations and union their sets.
// Step 3: Then process all "!=" equations:
//         If both variables belong to the same set → contradiction → return false.
// Step 4: If no conflicts found, return true.
//
// Key Idea:
// Equal variables should belong to the same group.
// If unequal variables fall into the same group → invalid.

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    // 🔍 Find function with Path Compression
    // Finds the ultimate parent (representative) of a node
    int find(int i){

        // Base case: if node is its own parent
        if(i == parent[i])
            return i;

        // Path compression optimization
        return parent[i] = find(parent[i]);
    }

    // 🔗 Union by Rank
    // Merges two sets efficiently
    void Union(int x, int y){

        int x_parent = find(x);
        int y_parent = find(y);

        // If already in same set, do nothing
        if(x_parent == y_parent)
            return;

        // Attach smaller rank tree under larger rank tree
        if(rank[x_parent] > rank[y_parent])
            parent[y_parent] = x_parent;

        else if(rank[y_parent] > rank[x_parent])
            parent[x_parent] = y_parent;

        // If ranks are equal, choose one as parent and increase rank
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {

        // Initialize DSU for 26 lowercase letters
        parent.resize(26);
        rank.resize(26, 0);

        for(int i=0; i<26; i++)
            parent[i] = i;

        // 🔹 Step 1: Process all "==" equations
        for(auto& s : equations){
            if(s[1] == '=')
                Union(s[0] - 'a', s[3] - 'a');
        }

        // 🔹 Step 2: Process all "!=" equations
        for(auto& s : equations){

            if(s[1] == '!'){

                int x_parent = find(s[0] - 'a');
                int y_parent = find(s[3] - 'a');

                // If both belong to same set → contradiction
                if(x_parent == y_parent)
                    return false;
            }
        }

        // No conflicts found
        return true;
    }
};