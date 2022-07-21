class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        int row_count = 0;
        vector<int> col_count(n, 0);
        for (int row=0; row<m; ++row) {
            for (int col=0; col<n; ++col) {
                if (row == 0 || grid[row - 1][col] == 'W') {
                    col_count[col] = 0;
                    for (int k=row; k < m && grid[k][col] != 'W'; ++k) {
                        if (grid[k][col] == 'E') {
                            col_count[col] ++;
                        }
                    }
                }
                if (col == 0 || grid[row][col - 1] == 'W') {
                    row_count = 0;
                    for (int k=col; k < n && grid[row][k] != 'W'; ++k) {
                        if (grid[row][k] == 'E') {
                            row_count ++;
                        }
                    }
                }
                if (grid[row][col] == '0') {
                    res = max(res, row_count + col_count[col]);
                }
            }
        }
        return res;
    }
};
// Time : O(RC)
// Space : O(C)