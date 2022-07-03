class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        queue<pair<int, int>> myQueue;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int num_land = 0;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    bool open = false;
                    myQueue.push({i, j});
                    grid[i][j] = 2;
                    num_land ++;
                    while (!myQueue.empty()) {
                        pair<int, int> front = myQueue.front();
                        myQueue.pop();
                        
                        if (front.first == 0 || front.second == 0 || front.first == m - 1 || front.second == n - 1) {
                            open = true;
                        }
                        for (int k=0; k<4; ++k) {
                            int x = front.first + dirs[k][0];
                            int y = front.second + dirs[k][1];
                            if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 0) {
                                myQueue.push({x, y});
                                grid[x][y] = 2;
                            }
                        }
                    }
                    if (open) {
                        num_land --;
                    }
                }
            }
        }
        return num_land;
    }
};
// Time : O(mn)
// Space : O(mn)