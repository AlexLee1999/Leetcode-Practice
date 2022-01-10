class Solution {
public:
    bool isMatch(string s, string p) {
        int s_size = s.size();
        int p_size = p.size();
        vector<vector<bool>> dp (s_size + 1, vector<bool>(p_size + 1, false));
        dp[0][0] = true;
        for (int i=0; i<p_size; ++i) {
            if (p[i] == '*') { //for case a*b*c* = ""
                dp[0][i+1] = dp[0][i-1];
            }
        }
        for (int i=0; i<s_size; ++i) {
            for (int j=0; j<p_size; ++j) {
                if (s[i] == p[j] || p[j] == '.') {
                    dp[i+1][j+1] = dp[i][j];
                }
                if(p[j] == '*') {
                    if (p[j-1] == '.' || p[j-1] == s[i]) {
                        dp[i+1][j+1] = dp[i][j+1];
                    }
                    dp[i+1][j+1] = dp[i+1][j+1] || dp[i+1][j-1];
                }
                
            }
        }
        return dp[s_size][p_size];
    }
};