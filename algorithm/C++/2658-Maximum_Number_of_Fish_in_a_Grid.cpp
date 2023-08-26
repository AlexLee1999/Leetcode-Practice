class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int max_result = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (!visited[i][j] && grid[i][j] > 0) {
                    int count = 0;
                    queue<pair<int, int>> myQueue;
                    myQueue.push({i, j});
                    visited[i][j] = true;
                    while (!myQueue.empty()) {
                        pair<int, int> front = myQueue.front();
                        myQueue.pop();
                        count += grid[front.first][front.second];
                        for (int i=0; i<4; ++i) {
                            int x = front.first + dirs[i].first;
                            int y = front.second + dirs[i].second;
                            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && grid[x][y] > 0) {
                                myQueue.push({x, y});
                                visited[x][y] = true;
                            }
                        } 
                    }
                    max_result = max(max_result, count);
                }
            }
        }
        return max_result;
    }
};