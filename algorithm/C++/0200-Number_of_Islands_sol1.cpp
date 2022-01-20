class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int island = 0;
        queue<pair<int, int>> Q;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == '1') {
                    island ++;
                    Q.push({i, j});
                    grid[i][j] = '0';
                    while (!Q.empty()) {
                        pair<int, int> land = Q.front();
                        int row = land.first;
                        int col = land.second;
                        Q.pop();
                        if (row-1>=0 && grid[row-1][col] == '1') {
                            Q.push({row-1, col});
                            grid[row-1][col] = '0';
                        }
                        if (row+1<m && grid[row+1][col] == '1') {
                            Q.push({row+1, col});
                            grid[row+1][col] = '0';
                        }
                        if (col-1>=0 && grid[row][col-1] == '1') {
                            Q.push({row, col-1});
                            grid[row][col-1] = '0';
                        }
                        if (col+1<n && grid[row][col+1] == '1') {
                            Q.push({row, col+1});
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }
        return island; // BFS Solution
    }
};