/*
    LeetCode Problem: 417. Pacific Atlantic Water Flow
    Topic: Multi-Source BFS

    Difficulty: Medium

    Tags:
    Graph, BFS, Matrix, Multi-Source BFS

    ✅ Approach:
    This solution uses two separate
    Multi-Source BFS traversals.

    Instead of checking every cell and
    trying to reach the oceans, we reverse
    the flow direction and start BFS from
    the oceans themselves.

    Goal:
    Find all cells from which water can
    flow to BOTH:
    - Pacific Ocean
    - Atlantic Ocean

    Important Concept:

    Water can flow from a cell to another
    cell having height less than or equal
    to the current cell.

    Instead of moving from land to ocean,
    we do the reverse:

    Start from ocean boundaries and move
    only to cells having height greater
    than or equal to the current cell.

    This tells us which cells can reach
    each ocean.

    ------------------------------------------------

    Why Multi-Source BFS?

    Pacific Ocean touches:
    - Top row
    - Left column

    Atlantic Ocean touches:
    - Bottom row
    - Right column

    Every boundary cell of an ocean acts
    as a source.

    Therefore:

    Pacific BFS:
    Start from all Pacific boundary cells.

    Atlantic BFS:
    Start from all Atlantic boundary cells.

    This makes it a classic
    Multi-Source BFS problem.

    ------------------------------------------------

    Reverse Flow Idea:

    Original flow:

        High Height
              ↓
        Low Height

    BFS Flow:

        Low Height
              ↑
        High Height

    While performing BFS:

    We can move from current cell to a
    neighboring cell only if:

        neighborHeight >= currentHeight

    because we are reversing the water flow.

    ------------------------------------------------

    Steps:

    1. Create Pacific visited matrix.

    2. Create Atlantic visited matrix.

    3. Push all Pacific boundary cells
       into Pacific queue.

       Sources:
       - First row
       - First column

    4. Push all Atlantic boundary cells
       into Atlantic queue.

       Sources:
       - Last row
       - Last column

    5. Run Multi-Source BFS from Pacific.

       Mark every cell that can reach
       Pacific Ocean.

    6. Run Multi-Source BFS from Atlantic.

       Mark every cell that can reach
       Atlantic Ocean.

    7. Traverse entire grid.

       If a cell is visited in both
       Pacific and Atlantic BFS,
       add it to answer.

    ------------------------------------------------

    Time Complexity:
    O(m × n)

    Each cell is visited at most once
    in Pacific BFS and once in Atlantic BFS.

    Space Complexity:
    O(m × n)

    For visited matrices and queues.
*/

class Solution {
public:

    using P = pair<int, int>;

    int m, n;

    /*
        Boundary check helper
    */
    bool inBound(int i, int j) {

        return i >= 0 &&
               i < m &&
               j >= 0 &&
               j < n;
    }

    /*
        Multi-Source BFS

        Starts from all ocean boundary cells
        and moves inward.

        A move is allowed only if:

        neighborHeight >= currentHeight

        because we are reversing the
        water flow direction.
    */
    void bfs(vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             queue<P>& que) {

        vector<vector<int>> directions{
            {0, 1},
            {0, -1},
            {-1, 0},
            {1, 0}
        };

        while(!que.empty()) {

            int size = que.size();

            while(size--) {

                auto [i, j] = que.front();
                que.pop();

                // Explore 4 neighbors
                for(auto& direction : directions) {

                    int i_ = i + direction[0];
                    int j_ = j + direction[1];

                    if(inBound(i_, j_) &&
                       !visited[i_][j_]) {

                        /*
                            Reverse flow condition

                            We can only move to a cell
                            having equal or greater height.
                        */
                        if(heights[i_][j_] <
                           heights[i][j])
                            continue;

                        visited[i_][j_] = true;

                        que.push({i_, j_});
                    }
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(
        vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        /*
            Stores cells reachable
            from Pacific Ocean
        */
        vector<vector<bool>> pacific_visited(
            m,
            vector<bool>(n, false)
        );

        /*
            Stores cells reachable
            from Atlantic Ocean
        */
        vector<vector<bool>> Atlantic_visited(
            m,
            vector<bool>(n, false)
        );

        /*
            Multi-source queues
        */
        queue<P> pacific_que;
        queue<P> Atlantic_que;

        /*
            Pacific Sources:
            Left column

            Atlantic Sources:
            Right column
        */
        for(int i = 0; i < m; i++) {

            pacific_que.push({i, 0});
            pacific_visited[i][0] = true;

            Atlantic_que.push({i, n - 1});
            Atlantic_visited[i][n - 1] = true;
        }

        /*
            Pacific Sources:
            Top row

            Atlantic Sources:
            Bottom row
        */
        for(int j = 0; j < n; j++) {

            pacific_que.push({0, j});
            pacific_visited[0][j] = true;

            Atlantic_que.push({m - 1, j});
            Atlantic_visited[m - 1][j] = true;
        }

        /*
            Cells reachable
            from Pacific Ocean
        */
        bfs(
            heights,
            pacific_visited,
            pacific_que
        );

        /*
            Cells reachable
            from Atlantic Ocean
        */
        bfs(
            heights,
            Atlantic_visited,
            Atlantic_que
        );

        vector<vector<int>> result;

        /*
            A cell can flow to both oceans
            if it is reachable in both BFS runs.
        */
        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(pacific_visited[i][j] &&
                   Atlantic_visited[i][j]) {

                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};