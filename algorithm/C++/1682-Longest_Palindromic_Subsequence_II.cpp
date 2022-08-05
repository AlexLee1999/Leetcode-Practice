class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<vector<int>>> table(n, vector<vector<int>>(n, vector<int>(26, 0))); 
        int max_len = 0;
        for (int i=n - 2; i >= 0; --i) {
            for (int j=i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    for (int k=0; k<26; ++k) {
                        if (k != (s[i] - 'a')) {
                            table[i][j][s[i] - 'a'] = max(table[i][j][s[i] - 'a'], table[i + 1][j - 1][k] + 2);
                        } else {
                            table[i][j][k] = max(table[i][j][k], table[i + 1][j - 1][k]);
                        }
                    }
                } else {
                    for (int k=0; k<26; ++k) {
                        table[i][j][k] = max(table[i][j - 1][k], table[i + 1][j][k]);
                    }
                }
            }
        }
        for (int i=0; i<n; ++i) {
            for (int j=i + 1; j < n; ++j) {
                for (int k=0; k<26; ++k) {
                    max_len = max(max_len, table[i][j][k]);
                }
            }
        }
        return max_len;
    }
};
// Time : O(n^2)
// Space : O(n^2)