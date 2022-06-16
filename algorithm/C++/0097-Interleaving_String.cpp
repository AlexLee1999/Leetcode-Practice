class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();

        if (m + n != s3.size()) {
            return false;
        }
        vector<vector<bool>> table(m + 1, vector<bool>(n + 1, false));
        for (int i=0; i<=m; ++i) {
            for (int j=0; j<=n; ++j) {
                if (i == 0 && j == 0) {
                    table[0][0] = true;
                } else {
                    if ((i > 0 && table[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (j > 0 && table[i][j - 1] && s2[j - 1] == s3[i + j - 1])) {
                        table[i][j] = true;
                    }
                }
                
            }
        }
        return table[m][n];
    }
};
// Time : O(mn)
// Space : O(mn)