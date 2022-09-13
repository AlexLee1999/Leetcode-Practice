class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int color = 2;
        unordered_map<int, int> areaSize;
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int max_area = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    queue<pair<int, int>> myQueue;
                    myQueue.push({i, j});
                    grid[i][j] = color;
                    area ++;
                    while(!myQueue.empty()) {
                        pair<int, int> front = myQueue.front();
                        myQueue.pop();
                        for (int k=0; k<4; ++k) {
                            int x = front.first + dirs[k][0];
                            int y = front.second + dirs[k][1];
                            if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1) {
                                myQueue.push({x, y});
                                grid[x][y] = color;
                                area ++;
                            }
                        }
                    }
                    areaSize[color] = area;
                    max_area = max(max_area, area);
                    color ++;
                }
            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 0) {
                    int area = 0;
                    unordered_set<int> colorSet;
                    for (int k=0; k<4; ++k) {
                        int x = i + dirs[k][0];
                        int y = j + dirs[k][1];
                        if (x >= 0 && y >= 0 && x < m && y < n && !colorSet.count(grid[x][y])) {
                            area += areaSize[grid[x][y]];
                            colorSet.insert(grid[x][y]);
                        }
                    }
                    max_area = max(max_area, area + 1);
                }
            }
        }
        return max_area;
    }
};
// Time : O(n^2)
// Space : O(n^2)