class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> myQueue;
        int num = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid2[i][j] == 1 && grid1[i][j] == 1) {
                    myQueue.push({i, j});
                    grid2[i][j] = 2;
                    bool open = false;
                    while (!myQueue.empty()) {
                        pair<int, int> front = myQueue.front();
                        myQueue.pop();
                        if (grid1[front.first][front.second] == 0) {
                            open = true;
                        }
                        for (int k=0; k<4; ++k) {
                            int x = front.first + dirs[k][0];
                            int y = front.second + dirs[k][1];
                            if (x >= 0 && y >= 0 && x < m && y < n && grid2[x][y] == 1) {
                                grid2[x][y] = 2;
                                myQueue.push({x, y});
                            }
                        }
                    }
                    if (!open) {
                        num ++;
                    }   
                }
            }
        }
        return num;
    }
};
// Time : O(mn)
// Space : O(mn)