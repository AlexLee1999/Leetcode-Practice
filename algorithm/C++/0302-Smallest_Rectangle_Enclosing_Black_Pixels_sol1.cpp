class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int left = INT_MAX;
        int right = INT_MIN;
        int up = INT_MAX;
        int down = INT_MIN;
        int m = image.size();
        int n = image[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (image[i][j] == '1') {
                    left = min(left, j);
                    right = max(right, j);
                    up = min(up, i);
                    down = max(down, i);
                }
            }
        }
        return (right - left + 1) * (down - up + 1);
    }
};
// Time : O(mn)
// Space : O(1)