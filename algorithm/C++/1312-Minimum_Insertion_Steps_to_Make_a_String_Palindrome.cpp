class Solution {
public:
    int minInsertions(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        int max_len = 0;
        vector<vector<int>> table(s.size() + 1, vector<int>(s.size() + 1, 0));
        for (int i=0; i<rev_s.size(); ++i) {
            for (int j=0; j<rev_s.size(); ++j) {
                if (s[i] == rev_s[j]) {
                    table[i + 1][j + 1] = table[i][j] + 1;
                } else {
                    table[i + 1][j + 1] = max(table[i + 1][j], table[i][j + 1]);
                }
                max_len = max(max_len, table[i + 1][j + 1]);
            }
        }
        return s.size() - max_len;
    }
};
// Time : O(n^2)
// Space : O(n^2)