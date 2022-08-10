class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
        vector<int> remain = piles;
        for (int i = n-2; i>=0; --i) {
            remain[i] += remain[i + 1];
        }
        for (int i=0; i<n; ++i) {
            table[i][n] = remain[i];
        }
        for (int i=n-1; i>=0; --i) {
            for (int j=n-1; j>=1; --j) {
                for (int x=1; x<=min(2*j, n - i); ++x) {
                    table[i][j] = max(table[i][j], remain[i] - table[i + x][max(j, x)]);
                }
            }
        }
        return table[0][1];
    }
};
// Time : O(n^2)
// Space : O(n^2)