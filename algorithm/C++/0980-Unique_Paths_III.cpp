class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int remain = 0;
        int start_row = 0;
        int start_col = 0;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                remain += (grid[i][j] >= 0);
                if (grid[i][j] == 1) {
                    start_row = i;
                    start_col = j;
                }
            }
        }
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int count = 0;
        backtrack(grid, start_row, start_col, count, remain, dirs);
        return count;
    }
    void backtrack(vector<vector<int>>& grid, int row, int col, int& count, int total_num, vector<vector<int>>& dirs) {
        if (total_num == 1 && grid[row][col] == 2) {
            count ++;
            return;
        }
        if (grid[row][col] == 2) {
            return;
        }
        if (grid[row][col] < 0) {
            return;
        }
        int tmp = grid[row][col];
        grid[row][col] = -1;
        total_num --;
        for (int i=0; i<4; ++i) {
            int x = row + dirs[i][0];
            int y = col + dirs[i][1];
            if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] >= 0) {
                backtrack(grid, x, y, count, total_num, dirs);
            }
        }
        grid[row][col] = tmp;
    }
};