class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 1e9 + 7;
        vector<vector<vector<long long>>> table(m + 1, vector<vector<long long>>(n + 1, vector<long long>(k, 0)));
        table[1][1][grid[0][0] % k] = 1;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                for (int l=0; l<k; ++l) {
                    table[i + 1][j + 1][(l + grid[i][j]) % k] += table[i + 1][j][l];
                    table[i + 1][j + 1][(l + grid[i][j]) % k] %= mod;
                    table[i + 1][j + 1][(l + grid[i][j]) % k] += table[i][j + 1][l];
                    table[i + 1][j + 1][(l + grid[i][j]) % k] %= mod;
                }
            }
        }
        return table[m][n][0] % mod;
    }
};
// Time : O(mnk)
// Space : O(mnk)