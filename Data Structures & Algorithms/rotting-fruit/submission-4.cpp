class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int time = 0, fresh = 0; 

        for (int r = 0; r < ROWS; r++)
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 2)
                    q.push({r, c});
                else if (grid[r][c] == 1)
                    fresh++;    
            }

        while (q.empty() == false && fresh > 0) {
            int size = q.size();
            for (int s = 0; s < size; s++) {

                auto [r, c] = q.front();
                q.pop();

                for (auto dir : direction) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || grid[nr][nc] != 1)
                        continue;

                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    fresh--;    
                }
            }
            time++;
        }  



        return fresh == 0 ? time : -1;                      
    }
};
