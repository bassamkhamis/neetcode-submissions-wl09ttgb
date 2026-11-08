class Solution {
   static constexpr int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void bfs(vector<vector<char>>& grid, int r, int c) {
        queue<pair<int, int>> qu;
        grid[r][c] = '0';
        qu.push({r, c});

        while(qu.empty() == false) {
            auto node = qu.front(); qu.pop();
            int row = node.first, col = node.second;
            for (int i = 0; i < 4; i++) {
                int nr = row + direction[i][0];
                int nc = col + direction[i][1];
                if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == '1') {
                    grid[nr][nc] = '0';
                    qu.push({nr, nc});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands{};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1')
                {
                    bfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};
