class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        unordered_set<string> mySet;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    string s = "";
                    dfs(grid, i, j, i, j, s);
                    mySet.insert(s);
                }
            }
        }
        return mySet.size();
    }
    void dfs(vector<vector<int>>& grid, int origin_x, int origin_y, int x, int y, string& s) {
        int m = grid.size();
        int n = grid[0].size();
        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
           grid[x][y] = 0;
            s += to_string(x-origin_x);
            s += to_string(y-origin_y);
            dfs(grid, origin_x, origin_y, x + 1, y, s);
            dfs(grid, origin_x, origin_y, x - 1, y, s);
            dfs(grid, origin_x, origin_y, x, y + 1, s);
            dfs(grid, origin_x, origin_y, x, y - 1, s);
        }
    }
};