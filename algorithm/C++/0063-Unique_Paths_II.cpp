class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = bstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> table(m, vector<int>(n, 0));
        table[0][0] = 1;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (i > 0 && obstacleGrid[i - 1][j] != 1) {
                    table[i][j] += table[i - 1][j];
                }
                if (j > 0 && obstacleGrid[i][j - 1] != 1) {
                    table[i][j] += table[i][j - 1];
                }
            }
        }
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        if (obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        return table[m - 1][n - 1];
    }
};
// Time : O(mn)
// Space : O(1)