class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int n = present.size();
        vector<vector<int>> table(n + 1, vector<int>(budget + 1, 0));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<=budget; ++j) {
                if (j >= present[i]) {
                    table[i + 1][j] = max(table[i][j], table[i][j - present[i]] + future[i] - present[i]);
                } else {
                    table[i + 1][j] = table[i][j];
                }
            }
        }
        return table[n][budget];
    }
};
// Time : O(nB)
// Space : O(nB)