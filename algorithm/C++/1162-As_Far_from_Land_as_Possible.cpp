class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> myQueue;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int land = 0;
        int water = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    myQueue.push({i, j});
                    land ++;
                } else {
                    water ++;
                }
            }
        }
        if (water == 0 || land == 0) {
            return -1;
        }
        
        int step = -1;
        while (!myQueue.empty()){
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                pair<int, int> front = myQueue.front();
                myQueue.pop();
                for (int k=0; k<4; ++k) {
                    int x = front.first + dirs[k][0];
                    int y = front.second + dirs[k][1];
                    if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 0) {
                        grid[x][y] = -1;
                        myQueue.push({x, y});
                    }
                }
            } 
            step ++;
        }
        return step;
    }
};
// Time : O(mn)
// Space : O(mn)