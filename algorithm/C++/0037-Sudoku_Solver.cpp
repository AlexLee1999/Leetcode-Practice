class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
    bool backtrack(vector<vector<char>>& board, int row, int col) {
        if (row == 9) {
            return true;
        }
        if (col == 9) {
            return backtrack(board, row + 1, 0);
            
        }
        if (board[row][col] != '.') {
            return backtrack(board, row, col + 1);
        }
        for (char i='1'; i<='9'; ++i) {
            if(valid(board, row, col, i)) {
                board[row][col] = i;
                if (backtrack(board, row, col + 1)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    bool valid(vector<vector<char>>& board, int row, int col, char num) {
        for (int i=0; i<board.size(); ++i) {
            if (board[i][col] == num) {
                return false;
            }
            if (board[row][i] == num) {
                return false;
            }
        }
        int row_start = (row / 3) * 3;
        int col_start = (col / 3) * 3;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                if (board[row_start + i][col_start + j] == num) {
                    return false;
                } 
            }
        }
        return true;
    }
};