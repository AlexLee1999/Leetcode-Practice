class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                table[i + 1][j + 1] = table[i][j + 1] + table[i + 1][j] + mat[i][j] - table[i][j];
            }
        }
        int left = 0;
        int right = min(m, n);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(table, threshold, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
    bool isPossible(vector<vector<int>>& table, int threshold, int len) {
        for (int i=1; i<=table.size() - len; ++i) {
            for (int j=1; j<=table[0].size() - len; ++j) {
                if (table[i + len - 1][j + len - 1] - table[i + len - 1][j - 1] - table[i - 1][j + len - 1] + table[i - 1][j - 1] <= threshold) {
                    return true;
                }
            }
        }
        return false;
    }
};
// Time : O(mnlog(min(m, n)))
// Space : O(mn)