class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<vector<int>> myQueue;
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        myQueue.push({0, 0});
        
        vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        grid[0][0] = 1;
        while (!myQueue.empty()) {
            vector<int> cell = myQueue.front();
            int x = cell[0];
            int y = cell[1];
            int step = grid[x][y];
            if (x == n-1 && y == n-1) {
                return step;
            }
            myQueue.pop();
            for (int j = 0; j<dirs.size(); ++j) {
                int x_new = x + dirs[j][0];
                int y_new = y + dirs[j][1];
                if (x_new < n && x_new >= 0 && y_new < n && y_new >= 0 && grid[x_new][y_new] == 0) {
                    myQueue.push({x_new, y_new});
                    grid[x_new][y_new] = step + 1;
                }
            }
        }
        return -1;
    }
};