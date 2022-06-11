class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> table(m + 1, vector<bool>(n + 1, false));
        table[0][0] = true;
        for (int j=0; j<n; ++j) {
            if (p[j] == '*') {
                table[0][j + 1] = table[0][j]; // Base Case : if s is empty string and p[j] is '*'
            } 
        }
        for (int j=0; j<n; ++j) {
            for (int i=0; i<m; ++i) {
                if (s[i] == p[j] || p[j] == '?') {
                    table[i + 1][j + 1] = table[i][j];
                }
                if (p[j] == '*') {
                    table[i + 1][j + 1] = table[i][j + 1] || table[i + 1][j];
                }
            }
        }
        return table[m][n];
    }
};
// Time : O(mn)
// Space ; O(mn)