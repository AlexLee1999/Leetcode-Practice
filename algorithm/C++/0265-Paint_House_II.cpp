class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        vector<vector<int>> table(n + 1, vector<int>(k, 0));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<k; ++j) {
                int min_cost_k = INT_MAX;
                for (int l=0; l<k; ++l) {
                    if (l != j) {
                        min_cost_k = min(min_cost_k, costs[i][j] + table[i][l]);
                    }
                }
                table[i + 1][j] = min_cost_k;
            }
        }
        int min_cost = INT_MAX;
        for (int i=0; i<k; ++i) {
            min_cost = min(min_cost, table[n][i]);
        }
        return min_cost;
    }
};
// Time : O(nk^2)
// Space : O(nk)