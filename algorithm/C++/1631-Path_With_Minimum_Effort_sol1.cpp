class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int left = 0;
        int right = 1000000;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (BFS(heights, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool BFS(vector<vector<int>>& heights, int limit) {
        int m = heights.size();
        int n = heights[0].size();
        queue<pair<int, int>> myQueue;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        myQueue.push({0, 0});
        
        while (!myQueue.empty()) {
            pair<int, int> front = myQueue.front();
            myQueue.pop();
            if (front.first == m -1 && front.second == n - 1) {
                return true;
            }
            for (int i=0; i<4; ++i) {
                int x = dirs[i][0] + front.first;
                int y = dirs[i][1] + front.second;
                if (x >= 0 && y >= 0 && x < m && y < n && !visited[x][y] && abs(heights[x][y] - heights[front.first][front.second]) <= limit) {
                    visited[x][y] = true;
                    myQueue.push({x, y});
                }
            }
        }
        return false;
    }
};
// Time : O(mn)
// Space : O(mn)