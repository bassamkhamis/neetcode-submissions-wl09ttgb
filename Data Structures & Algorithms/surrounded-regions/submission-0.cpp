class Solution {
    int direction [4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int ROWS, COLS;
    
    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] != 'O')
            return;

        board[r][c] = 'I';
        for (const auto& dir : direction) {
            dfs(board, r + dir[0], c + dir[1]);
        }    

    }
public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        // iterate over the border and mark any connected O's as I(invalid)
        // loop over right and left border
        for (int r = 0; r < ROWS; r++) {
            if (board[r][0] == 'O')           // left side
                dfs(board, r, 0);
            if (board[r][COLS - 1] == 'O')    // right side
                dfs(board, r, COLS - 1); 
        }
        // loop over the upp and lower border
        for (int c = 0; c < COLS; c++) {
            if (board[0][c] == 'O')            // upper side
                dfs(board, 0, c);
            if (board[ROWS - 1][c] == 'O')     // lower side
                dfs(board, ROWS - 1, c); 
        }

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'I')
                    board[r][c] = 'O';
                else if (board[r][c] == 'O') 
                    board[r][c] = 'X';   
            }
        }
    }
};
