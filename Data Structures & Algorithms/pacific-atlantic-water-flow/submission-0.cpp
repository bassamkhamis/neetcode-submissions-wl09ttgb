class Solution {
    static constexpr int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int ROWS, COLS;
    bool bfs(vector<vector<int>>& heights, int r, int c) {
        queue<pair<int, int>> q;
        vector<vector<bool>> seen(ROWS, vector<bool>(COLS, false));
        bool pacific = false;
        bool atlantic = false;
        q.push({r, c});

        while (q.empty() == false) {
            auto [row, col] = q.front();
            q.pop();

            pacific |=  (row == 0 || col == 0);
            atlantic |= ((row == ROWS - 1) || (col == COLS - 1));
            if (pacific && atlantic)
                return true;

            for (auto const dir: direction) {
                int nr = row + dir[0];
                int nc = col + dir[1];
                if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || seen[nr][nc] || heights[row][col] < heights[nr][nc])
                    continue;

                q.push({nr, nc});    
                seen[nr][nc] = true;
            }

        }
        return false;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<int>> res;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (bfs(heights, r, c)) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }
};
