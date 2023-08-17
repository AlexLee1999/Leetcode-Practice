class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int intMax = 1e9;
        vector<vector<int>> ans(m, vector<int>(n, intMax));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (mat[i][j] == 1) {
                    int left = i > 0 ? ans[i - 1][j] : intMax;
                    int up = j > 0 ? ans[i][j - 1] : intMax; 
                    ans[i][j] = min(ans[i][j], min(left, up) + 1);
                } else {
                    ans[i][j] = 0;
                }
            }
        }
        for (int i=m- 1; i>= 0; --i) {
            for (int j=n - 1; j >= 0; --j) {
                if (mat[i][j] == 1) {
                    int right = i < m - 1 ? ans[i + 1][j] : intMax;
                    int down = j < n - 1 ? ans[i][j + 1] : intMax; 
                    ans[i][j] = min(ans[i][j], min(right, down) + 1);
                } else {
                    ans[i][j] = 0;
                }
            }
        }
        return ans;
    }
};