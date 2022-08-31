class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int cost_0 = 0;
        int cost_1 = 0;
        int cost_2 = 0;
        for (int i=0; i<n; ++i) {
            int cost_0_tmp = cost_0;
            int cost_1_tmp = cost_1;
            int cost_2_tmp = cost_2;
            cost_0 = min(cost_1_tmp, cost_2_tmp) + costs[i][0];
            cost_1 = min(cost_0_tmp, cost_2_tmp) + costs[i][1];
            cost_2 = min(cost_1_tmp, cost_0_tmp) + costs[i][2];
        }
        return min(cost_0, min(cost_1, cost_2));
    }
};
// Time : O(n)
// Space : O(1)