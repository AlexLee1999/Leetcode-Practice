class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        queue<pair<int, int>> myQueue;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j] == '*') {
                    myQueue.push({i, j});
                    grid[i][j] = 'X';
                    break;
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
                    if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] != 'X') {
                        if (grid[x][y] == '#') {
                            return step + 1;
                        }
                        grid[x][y] = 'X';
                        myQueue.push({x, y});
                    }
                }
            }
            step ++;
        }
        return -1;
    }
};
// Time : O(mn)
// Space : O(mn)