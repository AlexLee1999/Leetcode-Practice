class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        int n = s.size();
        vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (s[i] == rev_s[j]) {
                    table[i + 1][j + 1] = table[i][j] + 1;
                } else {
                    table[i + 1][j + 1] = max(table[i + 1][j], table[i][j + 1]);
                }
            }
        }
        // Find the LCS between s and reverse(s)
        return table[n][n];
    }
};
// Time : O(n^2)
// Space : O(n^2)