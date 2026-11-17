/*
 1D row-major order: c + r * COLS_NUM
 convert it back: r = index / COLS_NUM = (c + r * COLS_NUM) / COLS_NUM = c/COLS_NUM + r * COLS_NUM / COLS_NUM = 0 + r
                  c =  index % COLS_NUM                 
*/

class Solution {
    static constexpr int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int ROWS, COLS;

    void dfs(vector<vector<int>>& heights, int r, int c, int preHeight, vector<bool>& visited) {
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || heights[r][c] < preHeight || visited[c + r * COLS])
            return;

        visited[c + r * COLS] = true;
        for (const auto& dir : direction) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            dfs(heights, nr, nc, heights[r][c], visited);
        }    
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<bool> pacific(ROWS * COLS, false), atlantic(ROWS * COLS, false);
        vector<vector<int>> res;

        for (int r = 0; r < ROWS; r++) {
            dfs(heights, r, 0, heights[r][0], pacific);
            dfs(heights, r, COLS - 1, heights[r][COLS - 1], atlantic);
        }

        for (int c = 0; c < COLS; c++) {
            dfs(heights, 0, c, heights[0][c], pacific);
            dfs(heights, ROWS - 1, c, heights[ROWS - 1][c], atlantic);
        }

        for (int i = 0; i < pacific.size(); i++) {
            if (pacific[i] && atlantic[i])
                res.push_back({i / COLS, i % COLS});
        }

        return res;
    }
};
