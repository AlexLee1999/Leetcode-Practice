class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int MAX_COST = 10000001;
        vector<vector<vector<int>>> table(m, vector<vector<int>>(target + 1, vector<int>(n, MAX_COST)));
    
        for (int color = 1; color<=n; ++color) {
            if (houses[0] == color) {
                table[0][1][color - 1] = 0;
            } else if (houses[0] == 0){
                table[0][1][color - 1] = cost[0][color - 1];
            }
        }
        for (int i=1; i<m; ++i) {
            for (int j = 1; j <= min(target, i + 1); ++j) {
                for (int color = 1; color<=n; ++color) {
                    if (houses[i] != 0 && color != houses[i]) {
                        continue;
                    }
                    int cur = MAX_COST;
                    for (int prev_color = 1; prev_color<=n; ++prev_color) {
                        if (prev_color != color) {
                            cur = min(cur, table[i - 1][j - 1][prev_color - 1]);
                        } else {
                            cur = min(cur, table[i - 1][j][prev_color - 1]);
                        }                 
                    }
                    if (houses[i] == 0) {
                        table[i][j][color - 1] = cur + cost[i][color - 1];
                    } else {
                        table[i][j][color - 1] = cur;
                    }
                }
            }
        }
        int min_cost = MAX_COST;
        for (int i=1; i<=n; ++i) {
            min_cost = min(min_cost, table[m - 1][target][i - 1]);
        }
        return min_cost == MAX_COST ? -1 : min_cost;
    }
};
// Time : O(mn^2T)
// Space : O(mnT)