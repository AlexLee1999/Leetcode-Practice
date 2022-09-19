class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<vector<long long>> table(m + 1, vector<long long>(n, 0));
        long long ans = INT_MIN;
        for (int i=0; i<m; ++i) {
            vector<long long> left_max(n, 0);
            left_max[0] = table[i][0];
            for (int j=1; j<n; ++j) {
                left_max[j] = max(left_max[j - 1] - 1, table[i][j]);
            }
            vector<long long> right_max(n, 0);
            right_max[n - 1] = table[i][n - 1];
            for (int j=n - 2; j>=0; --j) {
                right_max[j] = max(right_max[j + 1] - 1, table[i][j]);
            }
            for (int j=0; j<n; ++j) {
                table[i + 1][j] = points[i][j] + max(left_max[j], right_max[j]);
            }
        }
        for (int i=0; i<n; ++i) {
            ans = max(ans, table[m][i]);
        }
        return ans;
    }
};
// Time : O(mn)
// Space : O(mn)