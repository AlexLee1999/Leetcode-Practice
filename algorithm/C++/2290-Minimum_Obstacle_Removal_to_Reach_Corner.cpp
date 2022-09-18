class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        dis[0][0] = 0;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> myHeap;
        myHeap.push({0, {0, 0}});
        while (!myHeap.empty()) {
            int obs = myHeap.top().first;
            int x = myHeap.top().second.first;
            int y = myHeap.top().second.second;
            myHeap.pop();
            if (x == m - 1 && y == n - 1) {
                return obs;
            }
            for (int i=0; i<4; ++i) {
                int new_x = x + dirs[i][0];
                int new_y = y + dirs[i][1];
                if (new_x >= 0 && new_y >= 0 && new_x < m && new_y < n) {
                    if (obs + grid[new_x][new_y] < dis[new_x][new_y]) {
                        myHeap.push({obs + grid[new_x][new_y], {new_x, new_y}});
                        dis[new_x][new_y] = obs + grid[new_x][new_y];
                    }
                }
            }
        }
        return -1;
    }
};
// Time : O(mn)
// Space : O(mn)