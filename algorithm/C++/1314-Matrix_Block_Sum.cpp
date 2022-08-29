class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                table[i + 1][j + 1] = table[i + 1][j] + table[i][j + 1] + mat[i][j] - table[i][j];
            }
        }
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                int up = (i - k >= 0) ? i - k : 0;
                int down = (i + k < m) ? i + k : m - 1;
                int left = (j - k >= 0) ? j - k : 0;
                int right = (j + k < n) ? j + k : n - 1;
                mat[i][j] = table[down + 1][right + 1] - table[down + 1][left] - table[up][right + 1] + table[up][left];
            }
        }
        return mat;
    }
};
// Time : O(mn)
// Space : O(mn)