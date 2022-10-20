class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }
        vector<vector<int>> table(d, vector<int>(n, INT_MAX));
        table[0][0] = jobDifficulty[0];
        for (int i=1; i<n; ++i) {
            table[0][i] = max(table[0][i - 1], jobDifficulty[i]);
        }
        for (int i=1; i<d; ++i) {
            for (int j=i; j<n; ++j) {
                int cur_max = jobDifficulty[j];
                for (int k=j; k>=i; --k) {
                    cur_max = max(cur_max, jobDifficulty[k]);
                    table[i][j] = min(table[i][j], cur_max + table[i - 1][k - 1]);
                }
            }
        }
        return table[d - 1][n - 1];
    }
};
// Time : O(n^2d)
// Space : O(nd)