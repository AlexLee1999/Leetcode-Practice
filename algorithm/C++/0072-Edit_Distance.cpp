class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
        for (int i=0; i<=m; ++i) {
            table[i][0] = i; // Base Case : the edit distance is i characters
        }
        for (int i=0; i<=n; ++i) {
            table[0][i] = i; 
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (word1[i] == word2[j]) {
                    table[i + 1][j + 1] = table[i][j];
                } else {
                    table[i + 1][j + 1] = min(table[i][j + 1] + 1, table[i + 1][j] + 1);
                    table[i + 1][j + 1] = min(table[i + 1][j + 1], table[i][j] + 1);
                    // table[i + 1][j] delete
                    // table[i][j + 1] add
                    // table[i][j] replace
                }
            }
        }
        return table[m][n];
    }
};
// Time : O(mn)
// Space : O(mn)