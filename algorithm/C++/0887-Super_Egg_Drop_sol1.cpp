class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> table(n + 1, vector<int>(k + 1, 0));
        for (int i=1; i<=n; ++i) {
            table[i][1] = i;
        }
        for (int i=0; i<=k; ++i) {
            table[1][i] = 1;
        }
        for (int j=2; j<=k; ++j) {
            for (int i=2; i<=n; ++i) {
                int minMoves = INT_MAX;
                for (int l=1; l<=i; ++l) {
                    minMoves = min(minMoves, 1 + max(table[l - 1][j - 1], table[i - l][j]));
                }
                table[i][j] = minMoves;
            }
        }
        return table[n][k];
    }
};
// Time : O(n^2k)
// Space : O(nk)
// TLE