class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int PASS_MAX = 10000000;
        vector<vector<int>> dp(maxTime + 1, vector<int>(passingFees.size(), PASS_MAX));
        
        dp[0][0] = passingFees[0];
        for (int i=1; i<=maxTime; ++i) {
            for (int j=0; j<edges.size(); ++j) {
                if (edges[j][2] > i) {
                    continue;
                }
                int city1 = edges[j][0];
                int city2 = edges[j][1];
                int time = edges[j][2];
                dp[i][city1] = min(dp[i][city1], dp[i - time][city2] + passingFees[city1]);
                dp[i][city2] = min(dp[i][city2], dp[i - time][city1] + passingFees[city2]);
            }
        }
        int ans = PASS_MAX;
        for (int i=0; i<=maxTime; ++i) {
            ans = min(ans, dp[i][passingFees.size()-1]);
        }
        if (ans == PASS_MAX) {
            return -1;
        }
        return ans;
    }
};
// Time : O(TE) T = maxtime E = edge
// Space : O(TN)