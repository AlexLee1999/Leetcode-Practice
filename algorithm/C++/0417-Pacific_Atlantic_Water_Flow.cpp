class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        queue<pair<int, int>> atlanticQueue;
        queue<pair<int, int>> pacificQueue;
        vector<vector<int>> ans;
        for (int i=0; i<m; ++i) {
            pacific[i][0] = true;
            pacificQueue.push({i, 0});
            atlantic[i][n-1] = true;
            atlanticQueue.push({i, n-1});
        }
        for (int i=0; i<n; ++i) {
            pacific[0][i] = true;
            pacificQueue.push({0, i});
            atlantic[m-1][i] = true;
            atlanticQueue.push({m-1, i});
        }
        while (!pacificQueue.empty()) {
            pair<int, int> tmp = pacificQueue.front();
            pacificQueue.pop();
            pacific[tmp.first][tmp.second] = true;
            for (int i=0; i<4; ++i) {
                int new_x = tmp.first + dirs[i].first;
                int new_y = tmp.second + dirs[i].second;
                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && heights[new_x][new_y] >= heights[tmp.first][tmp.second] && !pacific[new_x][new_y]) {
                    pacificQueue.push({new_x, new_y});
                }
            }
            
        }
        while (!atlanticQueue.empty()) {
            pair<int, int> tmp = atlanticQueue.front();
            atlanticQueue.pop();
            atlantic[tmp.first][tmp.second] = true;
            for (int i=0; i<4; ++i) {
                int new_x = tmp.first + dirs[i].first;
                int new_y = tmp.second + dirs[i].second;
                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && heights[new_x][new_y] >= heights[tmp.first][tmp.second] && !atlantic[new_x][new_y]) {
                    atlanticQueue.push({new_x, new_y});
                }
            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (atlantic[i][j] && pacific[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};