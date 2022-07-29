class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        vector<vector<unsigned int>> table(m + 1, vector<unsigned int>(n + 1, 0));//table[i][j] indicates substr of s[0...i-1], t[0, j-1]
        for (int i=0; i<m; ++i) {
            table[i][0] = 1; //if t is empty, there is one posibility
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (i < j) {
                    continue;
                }
                if (s[i] == t[j]) {
                    table[i + 1][j + 1] = table[i][j + 1] + table[i][j];
                } else {
                    table[i + 1][j + 1] = table[i][j + 1];
                }
            }
        }
        return table[m][n];
    }
};
// Time : O(mn)
// Space : O(mn)