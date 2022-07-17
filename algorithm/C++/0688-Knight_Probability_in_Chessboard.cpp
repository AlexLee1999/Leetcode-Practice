class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> table(n, vector<double>(n, 0));
        table[row][column] = 1;
        vector<vector<int>> dirs = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, -2}, {-1, 2}, {-2, 1}, {-2, -1}};
        for (int move=0; move<k; ++move) {
            vector<vector<double>> tmp(n, vector<double>(n, 0));
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j) {
                    for (int l=0; l<8; ++l) {
                        int x = i + dirs[l][0];
                        int y = j + dirs[l][1];
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            tmp[x][y] += 0.125 * table[i][j];
                        }
                    }
                }
            }
            table = tmp;
        }
        double prob = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                prob += table[i][j];
            }
        }
        return prob;
    }
};