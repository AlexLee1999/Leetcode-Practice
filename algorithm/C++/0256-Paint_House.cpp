class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> table(n + 1, vector<int>(3, 0));
        for (int i=0; i<costs.size(); ++i) {
            table[i + 1][0] = costs[i][0] + min(table[i][1], table[i][2]);
            table[i + 1][1] = costs[i][1] + min(table[i][0], table[i][2]);
            table[i + 1][2] = costs[i][2] + min(table[i][0], table[i][1]);
        }
        int min_cost = min(table[n][0], table[n][1]);
        return min(min_cost, table[n][2]);
    }
};
// Time : O(n)
// Space : O(n)