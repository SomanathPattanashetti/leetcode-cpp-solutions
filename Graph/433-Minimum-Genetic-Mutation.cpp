/*
    LeetCode Problem: 433. Minimum Genetic Mutation
    Topic: BFS

    Difficulty: Medium

    Tags:
    Graph, BFS, String, Shortest Path

    ✅ Approach:
    This problem asks for the minimum number
    of mutations required to transform
    startGene into endGene.

    A mutation consists of changing exactly
    one character, and every intermediate
    gene must exist in the given bank.

    Since we need the minimum number of
    operations, BFS is the perfect choice.

    ------------------------------------------------

    Why BFS?

    BFS explores all possible mutations
    level by level.

    Level 0:
    startGene

    Level 1:
    All genes reachable using 1 mutation

    Level 2:
    All genes reachable using 2 mutations

    and so on...

    The first time we reach endGene,
    we are guaranteed to have found the
    minimum number of mutations.

    ------------------------------------------------

    Graph Interpretation

    Treat every valid gene as a node.

    An edge exists between two genes if
    they differ by exactly one character.

    Example:

    AACCGGTT
        |
    AACCGGTA
        |
    AAACGGTA

    Goal:
    Find the shortest path from
    startGene to endGene.

    BFS naturally finds the shortest path
    in an unweighted graph.

    ------------------------------------------------

    Mutation Generation

    For every position in the current gene:

    Replace the character with:

    A
    C
    G
    T

    Example:

    Current Gene:

        AACCGGTT

    Change first position:

        CACCGGTT
        GACCGGTT
        TACCGGTT

    Change second position:

        ACCCGGTT
        AGCCGGTT
        ATCCGGTT

    and so on...

    Every generated gene is checked:

    1. Must exist in bank.
    2. Must not be visited before.

    If valid:

    Push into BFS queue.

    ------------------------------------------------

    Steps:

    1. Store all bank genes inside a hash set.

    2. Create a visited set.

    3. Start BFS from startGene.

    4. For every gene:

       Generate all possible
       one-character mutations.

    5. If mutation exists in bank
       and is not visited:

       - Mark visited
       - Push into queue

    6. When endGene is reached,
       return current BFS level.

    7. If BFS finishes without reaching
       endGene, return -1.

    ------------------------------------------------

    Time Complexity:

    Let:

    N = number of genes in bank
    L = length of gene (8)

    For every gene we try:

        4 possible characters
        × L positions

    Time Complexity:

        O(N × 4 × L)

    Since L = 8 (constant),

        O(N)

    ------------------------------------------------

    Space Complexity:

    O(N)

    For:
    - Bank hash set
    - Visited set
    - BFS queue
*/

class Solution {
public:

    int minMutation(string startGene,
                    string endGene,
                    vector<string>& bank) {

        /*
            Fast lookup for valid genes
        */
        unordered_set<string> bank_set(
            begin(bank),
            end(bank)
        );

        /*
            Prevent revisiting genes
        */
        unordered_set<string> visited;

        /*
            BFS queue
        */
        queue<string> que;

        que.push(startGene);
        visited.insert(startGene);

        int level = 0;

        while(!que.empty()) {

            int size = que.size();

            while(size--) {

                string curr = que.front();
                que.pop();

                /*
                    Target gene found
                */
                if(curr == endGene)
                    return level;

                int n = curr.length();

                /*
                    Try all possible mutations
                */
                for(char ch : {'A', 'C', 'G', 'T'}) {

                    for(int i = 0; i < n; i++) {

                        /*
                            Create new mutation
                            from current gene
                        */
                        string temp = curr;

                        temp[i] = ch;

                        /*
                            Valid mutation:
                            - Exists in bank
                            - Not visited
                        */
                        if(visited.find(temp) ==
                               visited.end() &&
                           bank_set.find(temp) !=
                               bank_set.end()) {

                            visited.insert(temp);

                            que.push(temp);
                        }
                    }
                }
            }

            /*
                One mutation level completed
            */
            level++;
        }

        /*
            Transformation impossible
        */
        return -1;
    }
};  