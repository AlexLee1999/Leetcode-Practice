class TicTacToe {
public:
    TicTacToe(int n) {
        board = vector<vector<int>> (n, vector<int>(n, 0));
        
    }
    
    int move(int row, int col, int player) {
        board[row][col] = player;
        return check(row, col);
    }
private:
    vector<vector<int>> board;
    int check(int row, int col) {
        int winner;
        
        winner = checkRow(row);
        if (winner != 0) {
            return winner;
        }
        winner = checkCol(col);
        if (winner != 0) {
            return winner;
        }
        if (row == col) {
            winner = checkLeftDiag();
            if (winner != 0) {
                return winner;
            }
        }
        if (board.size() - row - 1 == col) {
            winner = checkRightDiag();
            if (winner != 0) {
                return winner;
            }
        }
        return 0;
    }
    int checkRow(int i) {
        int num = board[i][0];
        if (num == 0) {
            return 0;
        }
        for (int j=0; j<board.size(); ++j) {
            if (board[i][j] != num) {
                return 0;
            }
        }
        return num;
    }
    int checkCol(int i) {
        int num = board[0][i];
        if (num == 0) {
            return 0;
        }
        for (int j=0; j<board.size(); ++j) {
            if (board[j][i] != num) {
                return 0;
            }
        }
        return num;
    }
    int checkLeftDiag() {
        int num = board[0][0];
        if (num == 0) {
            return 0;
        }
        for (int j=0; j<board.size(); ++j) {
            if (board[j][j] != num) {
                return 0;
            }
        }
        return num;
    }
    int checkRightDiag() {
        int num = board[board.size() - 1][0];
        if (num == 0) {
            return 0;
        }
        for (int j=0; j<board.size(); ++j) {
            if (board[board.size() - 1 - j][j] != num) {
                return 0;
            }
        }
        return num;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */