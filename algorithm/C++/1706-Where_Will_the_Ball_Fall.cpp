class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n, -1);
        for (int i=0; i<n; ++i) {
            ans[i] = dfs(grid, i);
        }
        return ans;
    }
    int dfs(vector<vector<int>>& grid, int idx) {
        int row = 0;
        int col = idx;
        int m = grid.size();
        int n = grid[0].size();
        for (row=0; row < m; ++row) {
            if (col > 0 && grid[row][col] == -1 && grid[row][col - 1] == -1) {
                col --;
            } else if (col < n - 1 && grid[row][col] == 1 && grid[row][col + 1] == 1) {
                col ++;
            } else {
                return -1;
            }
        }
        return col;
    }
};
// Time : O(mn)
// Space : O(mn)