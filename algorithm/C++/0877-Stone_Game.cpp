class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp (n, vector<int>(n, 0));
        for (int i=0; i<n; ++i) {
            dp[i][i] = piles[i];
        }
        
        for (int len = 2; len <= piles.size(); ++len) {
            for (int start = 0; start <= piles.size() - len; ++start) {
                int end = start + len - 1;
                dp[start][end] = max(piles[start] - dp[start + 1][end], piles[end] - dp[start][end - 1]);
            }
        }
        return dp[0][n-1] > 0;
    }
};
// Time : O(n^2)
// Space : O(n^2)