class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> myQueue;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int fresh = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 2) {
                    myQueue.push({i, j});
                } else if (grid[i][j] == 1){
                    fresh ++;
                }
            }
        }
        int step = 0;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                pair<int, int> front = myQueue.front();
                myQueue.pop();
                for (int j=0; j<4; ++j) {
                    int x = front.first + dirs[j][0];
                    int y = front.second + dirs[j][1];
                    if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        fresh --;
                        myQueue.push({x, y});
                    }
                }
            }
            if (!myQueue.empty()) {
                step ++;
            }
            
        }
        return fresh == 0 ? step : -1;
    }
};
// Time : O(n^2)
// Space : O(n^2)