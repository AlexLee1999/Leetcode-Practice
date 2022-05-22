class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp (n, vector<bool>(n, false));
        int ans = 0;
        for(int i=0; i<n; ++i) {
            dp[i][i] = true;
            ans ++;
            if (i != n-1 && s[i] == s[i + 1]) {
                dp[i][i+1] = true;
                ans ++;
            }
        }
        for (int len = 2; len <= n; ++len) { //choose len from 2~n
            for (int i = 0; i + len <= n; ++i) { //choose starting index
                int j = i + len - 1; //calculate the end index
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    ans ++;
                }
            }
        }
        return ans;
    }
};