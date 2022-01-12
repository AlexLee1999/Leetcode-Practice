class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool isColumn = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                isColumn = true;
                //check if the first column needs to be set to zero before marking
            }
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                    cout <<i;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0) { //if matrix[0][0] == 0 it is set by the first row or initial zero => set first row to zero
            for (int i=0; i<n; ++i) {
                matrix[0][i] = 0;
            }
        }
        if (isColumn) { // does the first column need to set to zero?
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }

    }
};
