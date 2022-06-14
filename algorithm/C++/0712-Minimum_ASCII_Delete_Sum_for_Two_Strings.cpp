class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        int count1 = 0;
        int count2 = 0;
        vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
        for (int i=0; i<m; ++i) {
            count1 += (int)s1[i];
            for (int j=0; j<n; ++j) {
                if (i == 0) {
                    count2 += s2[j];
                }
                if (s1[i] == s2[j]) {
                    table[i+1][j+1] = table[i][j] + (int)s1[i];
                } else {
                    table[i+1][j+1] = max(table[i][j+1], table[i+1][j]);
                }
            }
        }
        return count1 + count2 - table[m][n] - table[m][n];
    }
};
// Time : O(mn)
// Space : O(mn)