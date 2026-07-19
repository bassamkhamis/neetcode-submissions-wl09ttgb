class Solution {
    static constexpr int directions[4][2] ={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r >= grid.size() || c >= grid[0].size() ||
            r < 0 || c < 0 || grid[r][c] == '0')
            return;

        grid[r][c] = '0';
        for (auto [dr, dc] : directions)
            dfs(grid, r + dr, c + dc);
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0)
            return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int islands {};

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] == '1') {
                    dfs(grid, r, c);
                    islands++;
                }
            }
        }
        return islands;
    }
};
