class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for (int i=0; i<m; ++i) {
            sortDiagonal(i, 0, mat);
        }
        for (int i=1; i<n; ++i) {
            sortDiagonal(0, i, mat);
        }
        return mat;
    }
    void sortDiagonal(int row, int col, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int i = row;
        int j = col;
        vector<int> arr;
        while (i < m && j < n) {
            arr.push_back(mat[i][j]);
            i ++;
            j ++;
        }
        sort(arr.begin(), arr.end());
        i = row;
        j = col;
        int ptr = 0;
        while (i < m && j < n) {
            mat[i][j] = arr[ptr];
            i ++;
            j ++;
            ptr ++;
        }
    }
};
// Time : O((n + m)log(n + m))
// Space : O(n + m)