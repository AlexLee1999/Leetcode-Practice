class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int, int>> myQueue;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = grid.size();
        int n = grid[0].size();
        int num_closed = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    myQueue.push({i, j});
                    grid[i][j] = 0;
                    bool open = false;
                    int num_island = 1;
                    while (!myQueue.empty()) {
                        pair<int, int> front = myQueue.front();
                        myQueue.pop();
                        if (front.first == 0 || front.second == 0 || front.first == m - 1 || front.second == n - 1) {
                            open = true;
                        }
                        for (int k = 0; k<4; ++k) {
                            int x = front.first + dirs[k][0];
                            int y = front.second + dirs[k][1];
                            if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1) {
                                grid[x][y] = 0;
                                myQueue.push({x, y});
                                num_island ++;
                            }
                        }
                    }
                    if (!open) {
                        num_closed += num_island;
                    }
                }
            }
        }
        return num_closed;
    }
};
// Time : O(mn)
// Space : O(mn)