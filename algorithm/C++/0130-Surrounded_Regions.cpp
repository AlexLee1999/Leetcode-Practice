class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> myQueue;
        int m = board.size();
        int n = board[0].size();
        for (int i=0; i<m; ++i) {
            if (board[i][0] == 'O') {
                myQueue.push({i, 0});
                board[i][0] = '$';
            }
            if (board[i][n-1] == 'O') {
                myQueue.push({i, n-1});
                board[i][n-1] = '$';
            }
        }
        for (int i=0; i<n; ++i) {
            if (board[0][i] == 'O') {
                myQueue.push({0, i});
                board[0][i] = '$';
            }
            if (board[m-1][i] == 'O') {
                myQueue.push({m-1, i});
                board[m-1][i] = '$';
            }
        }
        while(!myQueue.empty()) {
            pair<int, int> cell = myQueue.front();
            myQueue.pop();
            for (int j=0; j<dirs.size(); ++j) {
                int x_new = cell.first + dirs[j].first;
                int y_new = cell.second + dirs[j].second;
                if (x_new >= 0 && x_new < m && y_new >= 0 && y_new < n && board[x_new][y_new] == 'O') {
                    myQueue.push({x_new, y_new});
                    board[x_new][y_new] = '$';
                }
            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '$') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};