class Solution {
public:
    int numDistinct(string s, string t) {
        int ans = 0;
        int m = s.size();
        int n = t.size();
        vector<vector<uint64_t>> dp = vector(m+1,vector<uint64_t>(n+1, 0)); //dp[i][j] indicates substr of s[0...i-1], t[0, j-1]
        for (int i=0; i<=m; ++i) {
            dp[i][0] = 1; //if t is empty, there is one posibility
        }
        for(int i=1; i<=m; ++i) {
            for(int j=1; j<=n; ++j) {
                if (i<j) {
                    continue;
                }
                if(s[i-1] != t[j-1]) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};