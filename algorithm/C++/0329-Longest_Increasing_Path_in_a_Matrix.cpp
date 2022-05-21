class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> inedge(m, vector<int>(n, 0));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                for (int k=0; k<4; ++k) {
                    int x = i + dirs[k][0];
                    int y = j + dirs[k][1];
                    if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] < matrix[i][j]) {
                        inedge[i][j] ++;
                    }
                }
            }
        }
        queue<pair<int, int>> myQueue;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (inedge[i][j] == 0) {
                    myQueue.push({i, j});
                }
            }
        }
        int step = 0;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                pair<int, int> cell = myQueue.front();
                myQueue.pop();
                for (int k=0; k<4; ++k) {
                    int x = cell.first + dirs[k][0];
                    int y = cell.second + dirs[k][1];
                    if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[cell.first][cell.second]) {
                        inedge[x][y] --;
                        if (inedge[x][y] == 0) {
                            myQueue.push({x, y});
                        }
                    }
                }
            }
            step ++;
        }
        return step;
    }
};