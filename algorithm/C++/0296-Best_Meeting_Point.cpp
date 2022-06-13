class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> row;
        vector<int> col;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    row.push_back(i);
                }
            }
        }
        for (int i=0; i<grid[0].size(); ++i) {
            for (int j=0; j<grid.size(); ++j) {
                if (grid[j][i] == 1) {
                    col.push_back(i);
                }
            }
        }
        int best_x = row[row.size()/2]; // the median is the shortest to all points
        int best_y = col[col.size()/2];
        int distance = 0;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    distance += abs(i - best_x);
                    distance += abs(j - best_y);
                }
            }
        }
        return distance;
    }
};
// Time : O(mn)
// Space : O(mn)