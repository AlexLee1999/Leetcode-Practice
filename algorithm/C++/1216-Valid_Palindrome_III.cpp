class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        int ans = 0;
        vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
        for (int i=0; i<n; ++i) {
            table[i][i] = 1;
        }
        for (int i=n - 2; i>=0; --i) {
            for (int j=i + 1; j<n; ++j) {
                if (s[i] == s[j]) {
                    table[i][j] = table[i + 1][j - 1] + 2;
                } else {
                    table[i][j] = max(table[i + 1][j], table[i][j - 1]);
                }
                ans = max(ans, table[i][j]);
            }
        }
        return (n - ans) <= k;
    }
};
// Time : O(n^2)
// Space : O(n^2)