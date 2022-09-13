class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> table(k + 1, vector<int>(2, 0));
        for (int i=0; i<=k; ++i) {
            table[i][0] = INT_MIN;
        }
        for (int i=0; i<n; ++i) {
            for (int j=1; j<=k; ++j) {
                table[j][1] = max(table[j][1], table[j][0] + prices[i]);
                table[j][0] = max(table[j][0], table[j - 1][1] - prices[i]);
            }
        }
        return table[k][1];
    }
};
// Time : O(nk)
// Space : O(k)