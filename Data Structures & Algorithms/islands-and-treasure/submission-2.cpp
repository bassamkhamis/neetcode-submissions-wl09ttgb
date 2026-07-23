class Solution {
    static constexpr int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void bfs(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) // found one treasure
                    q.push({r, c});
            }
        }

        while (q.empty() == false) {
            auto [r, c] = q.front();
            q.pop();

            for (auto[dr, dc] : directions) {
                int row = dr + r;
                int col = dc + c;
                if (row < 0 || row >= rows ||
                    col < 0 || col >= cols ||
                    grid[row][col] != INT_MAX)
                    continue;

                grid[row][col] = grid[r][c] + 1; 
                q.push({row, col});
            }
        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        bfs(grid);
    }
};



// TLE
// class Solution {
//     static constexpr int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//     int min_dis = INT_MAX;
//     // TLE
//     void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visit, int r, int c, int dis)
//     {
//          if (r < 0 || r >= grid.size() ||
//           c < 0 || c >= grid[0].size() ||
//           visit[r][c] || grid[r][c] == -1)
//             return;

//          visit[r][c]  = true;
         
//          if (grid[r][c] == 0) {
//             min_dis = std::min(min_dis, dis);  
//          }
//         else {
//             for (auto[dr, dc] : directions) 
//                 dfs(grid, visit, r + dr, c + dc, dis + 1);
//         }

//         visit[r][c] = false;            
//     }
  
// public:
//     void islandsAndTreasure(vector<vector<int>>& grid) {
//         int rows = grid.size();
//         int cols = grid[0].size();
//         vector<vector<bool>> visit(rows, vector<bool>(cols, false));

//         for (int r = 0; r < rows; r++)
//         {
//             for (int c = 0; c < cols; c++)
//             {
//                 if (grid[r][c] == INT_MAX) {
//                     int dis{};
//                     dfs(grid, visit, r, c, dis);
//                     grid[r][c] = min_dis;
//                     min_dis = INT_MAX;
//                     visit = vector(rows, vector<bool>(cols, false));;
//                 }
//             }
//         }
//     }
// };
