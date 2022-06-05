class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    if (i == 0 || (i != 0 && grid[i - 1][j] == 0)) {
                        count ++;
                    }
                    if (i == grid.size() - 1 || (i != grid.size() - 1 && grid[i + 1][j] == 0)) {
                        count ++;
                    }
                    if (j == 0 || (j != 0 && grid[i][j - 1] == 0)) {
                        count ++;
                    }
                    if (j == grid[0].size() - 1 || (j != grid[0].size() - 1 && grid[i][j + 1] == 0)) {
                        count ++;
                    }
                }
            }
        }
        return count;
    }
};