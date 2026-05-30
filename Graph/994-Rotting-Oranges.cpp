/*
    LeetCode Problem: 994. Rotting Oranges
    Topic: Multi-Source BFS

    Difficulty: Medium

    Tags:
    Graph, BFS, Matrix, Multi-Source BFS

    ✅ Approach:
    This solution uses Multi-Source BFS
    to simulate the spread of rot from all
    initially rotten oranges simultaneously.

    Goal:
    Find the minimum number of minutes
    required to rot all fresh oranges.

    Important Concept:
    Every rotten orange can rot its
    adjacent fresh oranges in 1 minute.

    Since all rotten oranges start spreading
    at the same time, Multi-Source BFS is
    the optimal approach.

    ------------------------------------------------

    Why Multi-Source BFS?

    Normally BFS starts from one source.

    Here:
    - Multiple rotten oranges exist.
    - All start spreading together.
    - Each BFS level represents 1 minute.

    Therefore:
    Push all rotten oranges into the queue
    initially and perform BFS level by level.

    ------------------------------------------------

    BFS Flow:

    Minute 0:
    All initially rotten oranges are added
    into the queue.

    Minute 1:
    Their neighboring fresh oranges become rotten.

    Minute 2:
    Newly rotten oranges continue spreading.

    Continue until:
    - No fresh orange remains, OR
    - BFS finishes.

    ------------------------------------------------

    Steps:

    1. Traverse grid.
       - Count fresh oranges.
       - Push all rotten oranges into queue.

    2. If no fresh orange exists,
       return 0.

    3. Perform Multi-Source BFS.

    4. For every rotten orange:
       - Visit 4 directions.
       - Rot adjacent fresh oranges.
       - Decrease fresh count.
       - Push newly rotten orange into queue.

    5. Each BFS level represents
       one minute.

    6. After BFS:
       - If fresh oranges remain,
         return -1.
       - Otherwise return total minutes.

    ------------------------------------------------

    Time Complexity:
    O(m × n)

    Every cell is processed at most once.

    Space Complexity:
    O(m × n)

    Queue can contain all cells in
    the worst case.
*/

class Solution {
public:

    using P = pair<int, int>;

    // 4-directional movement
    vector<vector<int>> directions{
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0}
    };

    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int empty_cell = 0;
        int fresh_orange = 1;
        int rotten_orange = 2;

        int fresh_orange_count = 0;

        // Multi-source BFS queue
        queue<P> que;

        /*
            Find:
            1. All rotten oranges (sources)
            2. Total fresh oranges
        */
        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(grid[i][j] == rotten_orange) {

                    que.push({i, j});

                } else if(grid[i][j] == fresh_orange) {

                    fresh_orange_count++;
                }
            }
        }

        // No fresh oranges present
        if(fresh_orange_count == 0)
            return 0;

        /*
            Boundary check helper
        */
        auto isSafe = [&](int i, int j) {

            return i >= 0 &&
                   i < m &&
                   j >= 0 &&
                   j < n;
        };

        int minutes = 0;

        /*
            Multi-Source BFS

            Each BFS level
            = 1 minute
        */
        while(!que.empty()) {

            int size = que.size();

            while(size--) {

                auto [i, j] = que.front();
                que.pop();

                // Visit all 4 neighbors
                for(auto& direction : directions) {

                    int i_ = i + direction[0];
                    int j_ = j + direction[1];

                    if(isSafe(i_, j_)) {

                        /*
                            Rot fresh orange
                        */
                        if(grid[i_][j_] == fresh_orange) {

                            grid[i_][j_] = rotten_orange;

                            fresh_orange_count--;

                            que.push({i_, j_});
                        }
                    }
                }
            }

            // One BFS level completed
            minutes++;
        }

        /*
            If fresh oranges remain,
            impossible to rot all.
        */
        return fresh_orange_count == 0
                    ? minutes - 1
                    : -1;
    }
};