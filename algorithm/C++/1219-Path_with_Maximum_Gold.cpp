class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                int max_sum = 0;
                backtrack(i, j, grid, max_sum, 0);
                ans = max(ans, max_sum);
            }
        }
        return ans;
    }
    void backtrack(int row, int col, vector<vector<int>>& grid, int& max_sum, int cur_sum) {
        int m = grid.size();
        int n = grid[0].size();
        if (row >= m || col >= n || row < 0 || col < 0 || grid[row][col] == 0) {
            return;
        }
        cur_sum += grid[row][col];
        max_sum = max(max_sum, cur_sum);
        int tmp = grid[row][col];
        grid[row][col] = 0;
        backtrack(row, col + 1, grid, max_sum, cur_sum);
        backtrack(row + 1, col, grid, max_sum, cur_sum);
        backtrack(row - 1, col, grid, max_sum, cur_sum);
        backtrack(row, col - 1, grid, max_sum, cur_sum);
        grid[row][col] = tmp;
    }
};
// Time : O(4^mn)
// Space : O(4^mn)