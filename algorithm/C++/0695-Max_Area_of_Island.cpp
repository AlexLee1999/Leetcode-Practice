class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> myQueue;
        int max_area = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    int cur_area = 0;
                    myQueue.push({i, j});
                    grid[i][j] = 0;
                    while (!myQueue.empty()) {
                        pair<int, int> front = myQueue.front();
                        myQueue.pop();
                        cur_area ++;
                        for (int k=0; k<4; ++k) {
                            int x = front.first + dirs[k].first;
                            int y = front.second + dirs[k].second;
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                                grid[x][y] = 0;
                                myQueue.push({x, y});
                            }
                        }
                    }
                    max_area = max(max_area, cur_area);
                }
            }
        }
        return max_area;
    }
};
// Time : O(mn)
// Space : O(mn)