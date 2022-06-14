class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; j++) {
                if (word1[i] == word2[j]) {
                    table[i+1][j+1] = table[i][j] + 1;
                } else {
                    table[i+1][j+1] = max(table[i][j+1], table[i+1][j]);
                }
            }
        }
        return m - table[m][n] + n - table[m][n];
    }
};
// Time : O(mn)
// Space : O(mn)