class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> table(m, vector<int>(n, 0)); //slower than int 2d array
        int table[m][n];
        int min_dis = INT_MAX;
        for (int i=0; i<n; ++i) {
            table[m - 1][i] = grid[m - 1][i];
        }
        for (int i=n - 2; i>=0; --i) {
            for (int j=0; j<m; ++j) {
                table[i][j] = INT_MAX;
                for (int k=0; k<m; ++k) {
                    if (k != j) {
                        table[i][j] = min(table[i][j], table[i + 1][k]); 
                    }
                }
                table[i][j] += grid[i][j];
            }
        }
        
        for (int i=0; i<n; ++i) {
            min_dis = min(min_dis, table[0][i]);
        }
        return min_dis;
    }
};
// Time : O(mn)
// Space : O(mn)