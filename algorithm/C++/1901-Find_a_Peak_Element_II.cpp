class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int left_col = 0;
        int right_col = mat[0].size() - 1;
        while (left_col <= right_col) {
            int mid_col = left_col + (right_col - left_col) / 2;
            int max_row = 0;
            int max_val = 0;
            for (int i=0; i<mat.size(); ++i) {
                if (mat[i][mid_col] > max_val) {
                    max_val = mat[i][mid_col];
                    max_row = i;
                }
            }
            
            bool left_is_lower = false;
            bool right_is_lower = false;
            if (mid_col == 0 || mat[max_row][mid_col - 1] < max_val) {
                left_is_lower = true;
            }
            if (mid_col == mat[0].size() - 1 || mat[max_row][mid_col + 1] < max_val) {
                right_is_lower = true;
            }
            if (right_is_lower && left_is_lower) {
                return {max_row, mid_col};
            } else if (right_is_lower) {
                right_col = mid_col - 1;
            } else {
                left_col = mid_col + 1;
            }
        }
        return {};
    }
};
// Time : O(mlogn)
// Space : O(1)
// m is the row size, n is the col size