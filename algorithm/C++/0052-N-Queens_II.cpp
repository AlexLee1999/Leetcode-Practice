class Solution {
public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int ans = 0;
        backtrack(board, 0, ans);
        return ans;
    }
    void backtrack(vector<string>& board, int row, int& ans) {
        if (row == board.size()) {
            ans ++;
            return;
        }
        for (int i=0; i<board.size(); ++i) {
            if (valid(board, row, i)) {
                board[row][i] = 'Q';
                backtrack(board, row + 1, ans);
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
        while (i >= 0 && j < board.size()) {
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