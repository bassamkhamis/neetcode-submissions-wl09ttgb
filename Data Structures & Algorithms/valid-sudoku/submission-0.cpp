class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       for (int i=0; i<9; i++) {
            unordered_set<char> seen;
            for (int j=0; j<9; j++) {
                if (seen.count(board[i][j]))
                    return false;
                    
                if (board[i][j] != '.')
                    seen.insert(board[i][j]);
            }
       } 

        for (int i=0; i<9; i++) {
            unordered_set<char> seen;
            for (int j=0; j<9; j++) {
                if (seen.count(board[j][i]))
                    return false;
                    
                if (board[j][i] != '.')
                    seen.insert(board[j][i]);
            }
       } 

       for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                unordered_set<char> seen;
                for (int ii = i*3; ii < 3 + i*3; ii++) {
                    for (int jj = j*3; jj < j*3 + 3; jj++) {
                        if (seen.count(board[ii][jj]))
                            return false;
                    
                        if (board[ii][jj] != '.')
                            seen.insert(board[ii][jj]);
                    }
                }
            }
       }

       return true;
    }
};
