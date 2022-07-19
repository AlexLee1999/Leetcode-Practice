class Solution {
public:
    int kInversePairs(int n, int k) {
        int MOD = 1e9 + 7;
        vector<vector<int>> table(n + 1, vector<int>(k + 1, 0));
        table[0][0] = 1;
        for (int i=1; i<=n; ++i) {
            table[i][0] = 1;
            for (int j=1; j<=k; ++j) {
                table[i][j] = (table[i - 1][j] + table[i][j - 1]) % MOD;
                if (j >= i) {
                    table[i][j] = (table[i][j] - table[i - 1][j - i] + MOD) % MOD;
                }
            }
        }
        return table[n][k];
    }
};
// Time : O(nk)
// Space : O(nk)
/* Idea : dp[n][k] = dp[n - 1][k] + dp[n - 1][k-1] + ... + dp[n - 1][k - n + 1] 
Also, substitute k with k + 1 => dp[n][k+1] = dp[n - 1][k+1] + dp[n - 1][k] + ... + dp[n - 1][k + 1 - n + 1]
minus two equations
dp[n][k+1] = dp[n][k] + dp[n - 1][k+1] - dp[n - 1][k - n + 1]
substitute k + 1 with k
dp[n][k] = dp[n][k - 1] + dp[n - 1][k] - dp[n - 1][k - n]
with k >= n, dp[n-1][k-n] has valid number
*/
