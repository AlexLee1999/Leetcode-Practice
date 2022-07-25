class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> table(n, vector<int>(n, 0));
        for (int i=0; i<n; ++i) {
            table[i][i] = 1;
        }
        for (int i=n - 2; i >= 0; --i) {
            for (int j=i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    table[i][j] = table[i + 1][j - 1] + 2; // add s[i] and s[j] in s[i + 1 ~ j - 1]
                } else {
                    table[i][j] = max(table[i + 1][j], table[i][j - 1]); // Choose the longest subsequence(both i and j cannot be in the subsequence)
                }
            }
        }
        return table[0][n - 1];
    }
};
// Time : O(n^2)
// Space : O(n^2)