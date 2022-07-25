class Solution {
public:
    int twoEggDrop(int n) {
        int K = 2;
        vector<vector<int>> table(n + 1, vector<int>(K + 1, 0));
        for (int i=1; i<=n; ++i) {
            table[i][1] = i;
        }
        for (int i=0; i<=K; ++i) {
            table[1][i] = 1;
        }
        for (int j=2; j<=K; ++j) {
            for (int i=2; i<=n; ++i) {
                int minMoves = INT_MAX;
                for (int k=1; k<=i; ++k) {
                    minMoves = min(minMoves, 1 + max(table[k - 1][j - 1], table[i - k][j]));
                }
                table[i][j] = minMoves;
            }
        }
        return table[n][K];
    }
};
// Time : O(n^2k) k = 2
// Space : O(nk)