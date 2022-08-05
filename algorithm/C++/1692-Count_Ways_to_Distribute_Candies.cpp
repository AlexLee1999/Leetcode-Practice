class Solution {
public:
    int waysToDistribute(int n, int k) {
        if (n < k) {
            return 0;
        }
        int mod = 1e9 + 7;
        vector<vector<long long>> table(n + 1, vector<long long>(k + 1, 0));
        for (int i=1; i<=n; ++i) {
            table[i][1] = 1;
        }
        for (int j=2; j<=k; ++j) {
            for (int i=1; i<=n; ++i) {
                table[i][j] = (j * table[i - 1][j]) % mod + table[i - 1][j - 1] % mod;
            }
        }
        return table[n][k] % mod;
    } 
};
// Time : O(nk)
// Space : O(nk)