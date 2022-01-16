class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        int arrow_ptr = points[0][1];
        int arrow_num = 1;
        for (int i=1; i<points.size(); ++i) {
            if (points[i][0] <= arrow_ptr) {
                arrow_ptr = min(arrow_ptr, points[i][1]); //the end of the overlapping intervals
            }
            else {
                arrow_num ++;
                arrow_ptr = points[i][1]; //Non overlapping intervals, add more intervals
            }
        }
        return arrow_num;
    }
};