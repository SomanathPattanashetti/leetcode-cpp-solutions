/*
    LeetCode 1061: Lexicographically Smallest Equivalent String

    Topic: Graph, DFS

    Difficulty: Medium

    Tags:
    Graph,
    Depth First Search (DFS),
    Connected Components

    ✅ Approach:

    This solution models the character
    equivalence relations as an
    undirected graph.

    Observation:

    If two characters are equivalent,
    they belong to the same connected
    component.

    Example:

        a == b
        b == c

    Then:

        a, b, c

    all belong to the same component.

    Since equivalent characters can be
    substituted with each other, we
    should always replace a character
    with the lexicographically smallest
    character present in its component.

    Idea:

    1. Build an undirected graph using
       characters from s1 and s2.

    2. For every character in baseStr:

       - Perform DFS starting from that
         character.

       - Visit all characters belonging
         to the same connected component.

       - Find the smallest character
         reachable in that component.

    3. Append the smallest character
       to the answer.

    DFS Logic:

    - Mark current character as visited.

    - Assume current character is the
      smallest character initially.

    - Visit every unvisited neighbor.

    - Recursively find the smallest
      character reachable from the
      neighbor.

    - Update minimum character using:

          min(current_min,
              returned_min)

    - Return the smallest character
      found in the component.

    Why it works:

    - DFS explores the entire connected
      component.

    - Every character in the same
      component is equivalent.

    - The smallest character in that
      component is the lexicographically
      best replacement.

    Example:

        s1 = "abc"
        s2 = "bcd"

        Graph:

        a -- b -- c -- d

    Component:

        {a, b, c, d}

    Smallest Character:

        a

    Therefore:

        a -> a
        b -> a
        c -> a
        d -> a

    If baseStr = "dcba"

    Output:

        "aaaa"

    Time Complexity:

    O(M × (V + E))

    where,

    M = length of baseStr
    V = number of characters (26)
    E = number of equivalence edges

    For every character in baseStr,
    we perform a DFS traversal.

    Space Complexity:

    O(V + E)

    -> Adjacency list
    -> Visited array
    -> Recursive DFS stack

*/
class Solution {
public:

    char findSmallestChar(
        unordered_map<char, vector<char>>& adj,
        char curr_char,
        vector<bool>& visited) {

        // Mark current character visited
        int curr_char_index = curr_char - 'a';
        visited[curr_char_index] = true;

        // Assume current character is minimum
        char min_char = curr_char;

        // Visit all equivalent characters
        for(auto& adj_char : adj[curr_char]) {

            int adj_char_index = adj_char - 'a';

            if(!visited[adj_char_index]) {

                // Find minimum character
                // in the neighbor's component
                min_char = min(
                    min_char,
                    findSmallestChar(
                        adj,
                        adj_char,
                        visited
                    )
                );
            }
        }

        // Return smallest character
        // found in this component
        return min_char;
    }

    string smallestEquivalentString(
        string s1,
        string s2,
        string baseStr) {

        int n = s1.length();

        // Build graph
        unordered_map<char, vector<char>> adj;

        for(int i = 0; i < n; i++) {

            char u = s1[i];
            char v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string result;

        // Process every character
        // of baseStr
        for(char curr_char : baseStr) {

            vector<bool> visited(26, false);

            // Find smallest equivalent character
            char min_char =
                findSmallestChar(
                    adj,
                    curr_char,
                    visited
                );

            result.push_back(min_char);
        }

        return result;
    }
};