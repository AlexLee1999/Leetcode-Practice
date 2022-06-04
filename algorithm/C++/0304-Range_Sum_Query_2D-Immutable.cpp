class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        table = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                table[i+1][j+1] = table[i][j+1] + table[i+1][j] + matrix[i][j] - table[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return table[row2+1][col2+1] - table[row1][col2+1] - table[row2+1][col1] + table[row1][col1];
    }
private:
    vector<vector<int>> table;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */