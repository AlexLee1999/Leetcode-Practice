class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> table(n + 1, vector<int>(target + 1, 0));
        int mod = 1e9 + 7;
        for (int i=1; i<=min(target, k); ++i) {
            table[1][i] = 1;
        }
        
        for (int i=2; i<=n; ++i) {
            for (int j=i; j <= min(target, i * k); ++j) {
                for (int l=1; l<=k; ++l) {
                    table[i][j] = (table[i][j] + table[i - 1][max(0, j - l)]) % mod;
                }
            }
        }
        return table[n][target];
    }
};
// Time : O(ntk)
// Space : O(nk)