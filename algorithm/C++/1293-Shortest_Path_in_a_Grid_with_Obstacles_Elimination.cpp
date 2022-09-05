class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        set<pair<pair<int, int>, int>> visited;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int, int>, int>> myQueue;
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        myQueue.push({{0, 0}, k});
        int step = 0;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                int obstacles_left = myQueue.front().second;
                int row = myQueue.front().first.first;
                int col = myQueue.front().first.second;
                myQueue.pop();
                if (row == m - 1 && col == n - 1) {
                    return step;
                }
                for (int j=0; j<4; ++j) {
                    int x = row + dirs[j][0];
                    int y = col + dirs[j][1];
                    if (x >= 0 && y >= 0 && x < m && y < n) {
                        if (grid[x][y] == 1 && obstacles_left > 0 && !visited.count({{x, y}, obstacles_left - 1})) {
                            myQueue.push({{x, y}, obstacles_left - 1});
                            visited.insert({{x, y}, obstacles_left - 1});
                        } else if (grid[x][y] == 0 && !visited.count({{x, y}, obstacles_left})) {
                            myQueue.push({{x, y}, obstacles_left});
                            visited.insert({{x, y}, obstacles_left});
                        }
                    }
                }
            }
            step ++;
        }
        return -1;
    }
};
// Time : O(mnk)
// Space : O(mn)