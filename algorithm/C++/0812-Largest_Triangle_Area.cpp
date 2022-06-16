class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double max_area = 0;
        for (int i = 0; i < n-2; ++i) {
            for (int j = i + 1; j < n-1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    double dis1 = dis(points[i], points[j]);
                    double dis2 = dis(points[i], points[k]);
                    double dis3 = dis(points[j], points[k]);
                    max_area = max(max_area, heron(dis1, dis2, dis3));
                }
            }
        }
        return max_area;
    }
    double dis(vector<int>& a, vector<int>& b) {
        return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
    }
    double heron(double a, double b, double c) {
        double s = (a + b + c) / 2.0;
        return sqrt((s) * (s - a) * (s - b) * (s - c));
    }
};
// Time : O(n^3)
// Space : O(1)