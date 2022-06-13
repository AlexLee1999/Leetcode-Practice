class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> table(matrix.size(), vector<int>(matrix[0].size(), 0));
        int min_dis = INT_MAX;
        for (int i=0; i<matrix[0].size(); ++i) {
            table[matrix.size() - 1][i] = matrix[matrix.size() - 1][i];
        }
        for (int i=matrix[0].size() - 2; i>=0; --i) {
            for (int j=0; j<matrix.size(); ++j) {
                table[i][j] = table[i + 1][j] + matrix[i][j];
                if (j + 1 < matrix.size()) {
                   table[i][j] = min(table[i][j], table[i + 1][j + 1] + matrix[i][j]); 
                }
                if (j - 1 >= 0) {
                    table[i][j] = min(table[i][j], table[i + 1][j - 1] + matrix[i][j]); 
                }
            }
        }
        
        for (int i=0; i<matrix[0].size(); ++i) {
            min_dis = min(min_dis, table[0][i]);
        }
        return min_dis;
    }
};
// Time : O(mn)
// Space : O(mn)