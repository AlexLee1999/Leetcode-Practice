class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        vector<vector<int>> table(n + 1, vector<int>(k + 1, 0));
        for (int i=n; i>=0; --i) {
            for (int j=0; j<=k; ++j) {
                if (i == n) {
                    table[i][j] = 0;
                    continue;
                }
                if (j > 0) {
                    table[i][j] = table[i + 1][j - 1];
                } else {
                    table[i][j] = INT_MAX;
                }
                int max_delete = j;
                int count = 0;
                for (int l=i; l<n && max_delete >= 0; ++l) {
                    if (s[l] == s[i]) {
                        count ++;
                        table[i][j] = min(table[i][j], countLength(count) + table[l + 1][max_delete]);
                    } else {
                        max_delete --;
                    }
                }
            }
        }
        return table[0][k];
    }
    int countLength(int count) {
        if (count == 1) {
            return 1;
        } else if (count < 10) {
            return 2;
        } else if (count < 100) {
            return 3;
        }
        return 4;
    }
};
// Time : O(n^2k)
// Space : O(nk)