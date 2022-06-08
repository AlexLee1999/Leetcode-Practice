class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> checkTable (9, false);
        for (int i=0; i<9; ++i) {
                if (!checkRowCol(board, i, false, checkTable)) {
                    return false;
                }
                if (!checkRowCol(board, i, true, checkTable)) {
                        return false;
                    }
        }
        for (int i=0; i<9; i+=3) {
            for (int j=0; j<9; j+=3) {
                if (!checkBox(board, i, j, checkTable)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool checkRowCol(vector<vector<char>>& board, int num, bool isRow, vector<bool>& checkTable) {
        checkTable.assign(9, false);
        for (int i=0; i<9; ++i) {
            if (isRow) {
                if (board[num][i] != '.' ) {
                    if (!checkTable[board[num][i] - '0']) {
                        checkTable[board[num][i] - '0'] = true;
                    } else {
                        return false;
                    }
                }
            }
            else {
                if (board[i][num] != '.' ) {
                    if (!checkTable[board[i][num] - '0']) {
                        checkTable[board[i][num] - '0'] = true;
                    } else {
                        return false;
                    }
                }
            } 
        }
        return true;
    }
    bool checkBox(vector<vector<char>>& board, int row, int col, vector<bool>& checkTable) {
        checkTable.assign(9, false);
        for (int i=row; i<row + 3; ++i) {
            for (int j=col; j<col+3; ++j) {
                if (board[i][j] != '.' ) {
                    if (!checkTable[board[i][j] - '0']) {
                        checkTable[board[i][j] - '0'] = true;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// Time : O(n^2)
// Space : O(n^2)