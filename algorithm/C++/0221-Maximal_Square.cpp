class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
        int max_square = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j] == '1') {
                    table[i + 1][j + 1] = min(table[i][j + 1], table[i + 1][j]);
                    table[i + 1][j + 1] = min(table[i + 1][j + 1], table[i][j]);
                    table[i + 1][j + 1] ++;
                    max_square = max(max_square, table[i + 1][j + 1]);
                }
            }
        }
        return max_square * max_square;
    }
};
// Time : O(mn)
// Space : O(mn)