class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int min_dis = INT_MAX;
        int idx = -1;
        for (int i=0; i<points.size(); ++i) {
            if (x == points[i][0] && abs(points[i][1] - y) < min_dis) {
                idx = i;
                min_dis = abs(points[i][1] - y);
            } else if (y == points[i][1] && abs(points[i][0] - x) < min_dis) {
                idx = i;
                min_dis = abs(points[i][0] - x);
            }
        }
        return idx;
    }
};
// Time : O(n)
// Space : O(1)