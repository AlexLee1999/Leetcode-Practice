class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        colorIsland(grid);
        queue<pair<int, int>> myQueue;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    myQueue.push({i, j});
                }
            }
        }
        int step = 0;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            for (int l=0; l<size; ++l) {
                pair<int, int> front = myQueue.front();
                myQueue.pop();
                for (int k=0; k<4; ++k) {
                    int x = front.first + dirs[k][0];
                    int y = front.second + dirs[k][1];
                    if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] != 1 && grid[x][y] != 3) {
                        if (grid[x][y] == 2) {
                            return step;
                        }
                        grid[x][y] = 3;
                        myQueue.push({x, y});
                    }
                }
            }
            step ++;
        }
        return -1;
    }
    void colorIsland(vector<vector<int>>& grid) {
        queue<pair<int, int>> myQueue;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    myQueue.push({i, j});
                    grid[i][j] = 2;
                    while (!myQueue.empty()) {
                        pair<int, int> front = myQueue.front();
                        myQueue.pop();
                        for (int k=0; k<4; ++k) {
                            int x = front.first + dirs[k][0];
                            int y = front.second + dirs[k][1];
                            if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1) {
                                grid[x][y] = 2;
                                myQueue.push({x, y});
                            }
                        }
                    }
                    return;
                }
            }
        }
    }
};
// Time : O(mn)
// Space : O(mn)