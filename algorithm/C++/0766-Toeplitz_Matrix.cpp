class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i=0; i<m; ++i) {
            if (!check(matrix, i, 0, matrix[i][0])) {
                return false;
            }
        }
        for (int i=0; i<n; ++i) {
            if (!check(matrix, 0, i, matrix[0][i])) {
                return false;
            }
        }
        return true;
    }
    bool check(vector<vector<int>>& matrix, int x, int y, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        while (x < m && y < n) {
            if (matrix[x][y] != target) {
                return false;
            }
            x ++;
            y ++;
        }
        return true;
    }
};
// Time : O(m + n)
// Space : O(1)