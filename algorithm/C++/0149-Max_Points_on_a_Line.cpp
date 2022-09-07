class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 3) {
            return points.size();
        }
        int max_num = 0;
        for (int i=0; i<points.size(); ++i) {
            unordered_map<double, int> myMap;
            for (int j = i + 1; j < points.size(); ++j) {
                double dx = points[i][0] - points[j][0];
                double dy = points[i][1] - points[j][1];
                double slope = dy / dx;
                if (slope == (-1/double(0))) {
                    slope = 1/double(0);
                }
                myMap[slope] ++;
            }
            for (auto it = myMap.begin(); it != myMap.end(); ++it) {
                max_num = max(max_num, it->second + 1);
            }
        }
        return max_num;
    }
};
// Time : O(n^2)
// Space : O(n)