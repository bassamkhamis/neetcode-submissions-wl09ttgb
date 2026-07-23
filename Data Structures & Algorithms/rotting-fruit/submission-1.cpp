class Solution {
    static constexpr int directios[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int bfs(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int times{};
        int fresh{};

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1)
                    fresh++;
                else if (grid[r][c] == 2)
                    q.push({r, c});           
            }
        }

        while (q.empty() == false) {
            int _fresh = fresh;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto[dr, dc] : directios) {
                    int row = dr + r;
                    int col = dc + c;

                    if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != 1)
                        continue;

                    fresh--;
                    grid[row][col] = 2;
                    q.push({row, col});
                }
            }  
            if (_fresh != fresh) // check if there are any changes
                times++;
        }
        return fresh == 0 ? times : -1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};
