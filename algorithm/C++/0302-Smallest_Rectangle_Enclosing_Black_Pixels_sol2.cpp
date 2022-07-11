class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int left = leftBound(image, y);
        int right = rightBound(image, y);
        int up = upBound(image, x);
        int low = lowBound(image, x);
        return (right - left + 1)*(low - up + 1);
    }
    bool rowHasZero(vector<vector<char>>& image, int row) {
        for (int i=0; i<image[0].size(); ++i) {
            if (image[row][i] == '1') {
                return true;
            }
        }
        return false;
    }
    bool colHasZero(vector<vector<char>>& image, int col) {
        for (int i=0; i<image.size(); ++i) {
            if (image[i][col] == '1') {
                return true;
            }
        }
        return false;
    }
    int upBound(vector<vector<char>>& image, int x) {
        int left = 0;
        int right = x;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (rowHasZero(image, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    int lowBound(vector<vector<char>>& image, int x) {
        int left = x;
        int right = image.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (rowHasZero(image, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
    int leftBound(vector<vector<char>>& image, int x) {
        int left = 0;
        int right = x;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (colHasZero(image, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    int rightBound(vector<vector<char>>& image, int x) {
        int left = x;
        int right = image[0].size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (colHasZero(image, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};
// Time : O(mlogn + nlogm)
// Space : O(1)