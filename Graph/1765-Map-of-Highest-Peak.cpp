/*
    LeetCode Problem: 1765. Map of Highest Peak
    Topic: Multi-Source BFS

    Difficulty: Medium

    Tags:
    Graph, BFS, Matrix, Multi-Source BFS

    ✅ Approach:

    We are given a map containing:

    1 = Water cell
    0 = Land cell

    We must assign heights such that:

    1. Every water cell has height 0.
    2. Adjacent cells differ by at most 1.
    3. The maximum possible height is achieved.

    ------------------------------------------------

    Key Observation

    Water cells must always have height 0.

    Therefore, every land cell's height
    depends on its distance from the
    nearest water cell.

    Example:

        W  L  L

        0  1  2

    The farther a land cell is from water,
    the larger its height.

    So the problem becomes:

    "Find the shortest distance from every
    cell to the nearest water cell."

    ------------------------------------------------

    Why Multi-Source BFS?

    We have multiple water cells.

    Instead of running BFS from every
    water cell separately, we push all
    water cells into the queue initially.

    BFS then expands simultaneously from
    all water sources.

    This guarantees that the first time
    a cell is visited, we have found its
    minimum distance from water.

    That minimum distance becomes its height.

    ------------------------------------------------

    Example

    Input:

        0 1
        0 0

    Initialize:

        -1 0
        -1 -1

    Queue:

        (0,1)

    BFS Expansion:

    Level 0:

        -1 0
        -1 -1

    Level 1:

        1 0
        -1 1

    Level 2:

        1 0
        2 1

    Result:

        1 0
        2 1

    ------------------------------------------------

    BFS Logic

    Water Cells:

        Height = 0

    Land Cells:

        Height = -1 (unvisited)

    During BFS:

    If neighboring cell is unvisited:

        neighbor_height =
            current_height + 1

    Push neighbor into queue.

    ------------------------------------------------

    Steps:

    1. Create a height matrix initialized
       with -1.

    2. Push all water cells into the queue.

    3. Set water cell height = 0.

    4. Perform Multi-Source BFS.

    5. For every unvisited neighbor:

       - Assign:
         height = current + 1

       - Push into queue.

    6. Continue until queue becomes empty.

    7. Return the height matrix.

    ------------------------------------------------

    Why Does It Work?

    BFS explores cells level by level.

    Level 0:
        Water cells

    Level 1:
        Distance 1 from water

    Level 2:
        Distance 2 from water

    and so on...

    Thus every cell receives the shortest
    distance from any water cell.

    This automatically maximizes heights
    while satisfying all constraints.

    ------------------------------------------------

    Time Complexity:

    Let:

        m = rows
        n = columns

    Every cell is visited exactly once.

    Time:

        O(m × n)

    ------------------------------------------------

    Space Complexity:

    Height Matrix:
        O(m × n)

    BFS Queue:
        O(m × n)

    Total:

        O(m × n)
*/

class Solution {
public:

    using P = pair<int, int>;

    /*
        4-directional movement
    */
    vector<vector<int>> directions{
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    vector<vector<int>> highestPeak(
        vector<vector<int>>& isWater) {

        int m = isWater.size();
        int n = isWater[0].size();

        int water = 1;
        int not_visited = -1;

        /*
            Result height matrix

            Water -> 0
            Land  -> -1 initially
        */
        vector<vector<int>> heights(
            m,
            vector<int>(n, not_visited)
        );

        /*
            Multi-source BFS queue
        */
        queue<P> que;

        /*
            Add all water cells
            as BFS sources
        */
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(isWater[i][j] == water) {

                    heights[i][j] = 0;

                    que.push({i, j});
                }
            }
        }

        /*
            Boundary check
        */
        auto isSafe = [&](int i, int j) {

            return i >= 0 &&
                   i < m &&
                   j >= 0 &&
                   j < n;
        };

        /*
            Multi-source BFS
        */
        while(!que.empty()) {

            int size = que.size();

            while(size--) {

                auto [i, j] = que.front();
                que.pop();

                /*
                    Explore all neighbors
                */
                for(auto& direction :
                    directions) {

                    int i_ =
                        i + direction[0];

                    int j_ =
                        j + direction[1];

                    /*
                        First visit means
                        shortest distance
                        from water found
                    */
                    if(isSafe(i_, j_) &&
                       heights[i_][j_] ==
                       not_visited) {

                        heights[i_][j_] =
                            heights[i][j] + 1;

                        que.push({i_, j_});
                    }
                }
            }
        }

        return heights;
    }
};