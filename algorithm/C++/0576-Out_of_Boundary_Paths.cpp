class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int count = 0;
        int mod = 1e9 + 7;
        vector<vector<long>> table(m, vector<long>(n, 0));
        table[startRow][startColumn] = 1;
        for (int i=0; i<maxMove; ++i) {
            vector<vector<long>> tmp (m, vector<long>(n, 0));
            for (int j=0; j<m; ++j) {
                for (int k=0; k<n; ++k) {
                    for (int l=0; l<4; ++l) {
                        int x = j + dirs[l][0];
                        int y = k + dirs[l][1];
                        if (x < 0 || x >= m || y < 0 || y >= n) {
                            count = (count + table[j][k]) % mod;
                        } else {
                            tmp[x][y] = (tmp[x][y] + table[j][k]) % mod;
                        }
                    }
                }
            }
            table = tmp;
        }
        return count % mod;
    }
};
// Time : O(mnN)
// Space : O(mn)