class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> table(n, vector<int>(m, -1));
        bool rowflag = false;
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        for (int i=0; i<n; ++i) {
            if (obstacleGrid[i][0] == 0 && !rowflag) {
                table[i][0] = 1;
            } else {
                table[i][0] = 0;
                rowflag = true;
            }
        }
        bool colflag = false;
        for (int i=0; i<m; ++i) {
            if (obstacleGrid[0][i] == 0 && !colflag) {
               table[0][i] = 1; 
            } else {
                table[0][i] = 0;
                colflag = true;
            }
        }
        for (int i=1; i<n; ++i) {
            for (int j=1; j<m; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    table[i][j] = table[i][j-1] + table[i-1][j];
                } else {
                    table[i][j] = 0;
                }
            }
        }
        return table[n-1][m-1];
    }
};