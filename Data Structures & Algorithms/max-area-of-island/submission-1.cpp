class Solution {
    static constexpr int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int bfs(vector<vector<int>>& grid, int row, int col) {
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = 0;
        int res = 1;

        while (q.empty() == false) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + direction[i][0];
                int nc = c + direction[i][1];

                if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size() || grid[nr][nc] == 0)
                    continue;

                res++;
                grid[nr][nc] = 0; // mark as visited 
                q.push({nr, nc});   
            }
        }

        return res;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxArea{};

        for (int r=0; r < row; r++) {
            for (int c=0; c < col; c++) {
                if (grid[r][c] == 1)
                    maxArea = std::max(bfs(grid, r, c), maxArea);
            }
        }

        return maxArea;
    }
};
