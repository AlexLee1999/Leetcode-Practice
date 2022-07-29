class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() <= 2) {
            return true;
        }
        double slope = (double)(coordinates[0][1] - coordinates[1][1]) / (double)(coordinates[0][0] - coordinates[1][0]);
        double intercept = coordinates[0][1] - slope * coordinates[0][0];
        if (slope == 1/double(0) || slope == -1/double(0)) {
            for (int i=2; i<coordinates.size(); ++i) {
                if (!isVertical(coordinates[0][0], coordinates[i][0], coordinates[i][1])) {
                    return false;
                }
            }
        } else {
            for (int i=2; i<coordinates.size(); ++i) {
                if (!inLine(slope, intercept, coordinates[i][0], coordinates[i][1])) {
                    return false;
                }
            }
        }
        return true;
    }
    bool inLine(double m, double b, int x, int y) {
        return (double)y == m * x + b;
    }
    bool isVertical(double b, int x, int y) {
        return x == b;
    }
};
// Time : O(n)
// Space : O(1)