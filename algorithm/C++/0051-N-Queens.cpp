class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        backtrack(board, 0, res);
        
        return res;
    }
    void backtrack(vector<string>& board, int row, vector<vector<string>>& res) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        for (int i=0; i<board.size(); ++i) {
            if (valid(board, row, i)) {
                board[row][i] = 'Q';
                backtrack(board, row + 1, res);
                board[row][i] = '.';
            }
        }
    }
    bool valid(vector<string>& board, int row, int col) {
        for (int i=0; i<row; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        int i = row;
        int j = col;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i --;
            j --;
        }
        i = row;
        j = col;
        while (j < board.size() && i >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i --;
            j ++;
        }
        return true;
    }
};
// Time : O(n!)
// Space : O(n^2)