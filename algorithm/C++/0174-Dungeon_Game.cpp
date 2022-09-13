class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> table(m + 1, vector<int>(n + 1, INT_MAX));
        table[m][n - 1] = 1;
        table[m - 1][n] = 1;
        for (int i=m - 1; i >= 0; --i) {
            for (int j=n - 1; j >= 0; --j) {
                table[i][j] = max(1, min(table[i + 1][j], table[i][j + 1]) - dungeon[i][j]);
            }
        }
        return table[0][0];
    }
};
// Time : O(mn)
// Space : O(mn)