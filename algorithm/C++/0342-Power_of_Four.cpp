class Solution {
public:
    bool isPowerOfFour(int n) {
        int left = 0;
        int right = n;
        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (pow(4, mid) == n) {
                return true;
            } else if (pow(4, mid) > n) {
                right = mid - 1;
            } else if (pow(4, mid) < n) {
                left = mid + 1;
            }
        }
        return false;
    }
};