class Solution {
public:
    int arrangeCoins(int n) {
        long long left = (long long)0;
        long long right = (long long)n;
        while (left <= right) {
            long long mid = left + (right-left) /2;
            long long num = (mid * (mid + 1)) / 2;
            if (num > n) {
                right = mid - 1;
            } else if (num < n) {
                left = mid + 1;
            } else if (num == n) {
                return (int)mid;
            }
        }
        return right;
    }
};
// Time : O(logn)
// Space : O(1)