class Solution {
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();   
        queue<pair<int, int>> q;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == 0)
                    q.push({r, c});
            }
        }

        while (q.empty() == false) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i=0; i < 4; i++) {
                int nr = r + direction[i][0];
                int nc = c + direction[i][1];

                if (nr < 0 || nc < 0 || nr >= row || nc >= col || grid[nr][nc] != INT_MAX)
                    continue;

                grid[nr][nc] = grid[r][c] + 1;

                q.push({nr, nc});    
            }
        }
    }
};
