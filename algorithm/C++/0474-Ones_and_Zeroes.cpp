class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));//dp[i][j] contains the number of strings of i zeros and j ones
        for (int k=0; k<strs.size(); ++k) {
            int zeros = 0;
            int ones = 0;
            for (int l=0; l<strs[k].size(); ++l) {
                if (strs[k][l] - '0' == 1) {
                    ones++;
                } else {
                    zeros++;
                }
            }
            for (int i=m; i>=zeros; --i) {
                for (int j=n; j>=ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};