class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> mat = vector<vector<int>>(n, vector<int>(n, 0));
        int x = 0;
        int y = 0;
        int d = 0;
        for (int i=0; i<n*n; ++i) {
            mat[x][y] = i + 1;
            if (x + dirs[d][0] >= n || y + dirs[d][1] >= n || x + dirs[d][0] < 0 || y + dirs[d][1] < 0 || mat[x + dirs[d][0]][y + dirs[d][1]] != 0) {
                d ++;
                d %= 4;
            }
            x += dirs[d][0];
            y += dirs[d][1];
        }
        return mat;
    }
};
// Time : O(n^2)
// Space : O(n^2)