class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = 0;
        int right = n * n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (bfs(grid, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool bfs(vector<vector<int>>& grid, int limit) {
        queue<pair<int, int>> myQueue;
        if (grid[0][0] > limit) {
            return false;
        }
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        myQueue.push({0, 0});
        visited[0][0] = true;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!myQueue.empty()) {
            pair<int, int> front = myQueue.front();
            myQueue.pop();
            if (front.first == n - 1 && front.second == n - 1) {
                return true;
            }
            for (int i=0; i<4; ++i) {
                int x = dirs[i][0] + front.first;
                int y = dirs[i][1] + front.second;
                if (x >= 0 && y >= 0 && x < n && y < n && !visited[x][y] && grid[x][y] <= limit) {
                    myQueue.push({x, y});
                    visited[x][y] = true;
                }
            }
        }
        return false;
    }
};
// Time : O(n^2logn)
// Space : O(n^2)