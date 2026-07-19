class Solution {
    static constexpr int directions[4][2] ={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int bfs(vector<vector<int>>& grid, int r, int c) {
        std::queue<pair<int, int>> q;

        grid[r][c] = 0;
        q.push({r, c});
        int size = 1;
        while(q.empty() == 0)
        {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : directions)
            {
                int row = dr + r;
                int col = dc + c;
                if (row >= 0 && row < grid.size() &&
                    col >= 0 && col < grid[0].size() &&
                    grid[row][col] == 1)
                    {
                        q.push({row, col});
                        grid[row][col] = 0;
                        size++;
                    }
            }
        }
        return size;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int max_size {};

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] == 1) {
                    int res = bfs(grid, r, c);
                    max_size = std::max(max_size, res);;
                }
            }
        }
        return max_size;
    }
};
