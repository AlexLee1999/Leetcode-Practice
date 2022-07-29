class Solution {
public:
    int preimageSizeFZF(int k) {
        long long left = 0;
        long long right = LLONG_MAX;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long count = countZeros(mid);
            if (count == k) {
                return 5; // Only 5 numbers will have the same trailing zeros.
            } else if (count > k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return 0;
    }
    long long countZeros(long long n) {
        long long count = 0;
        while (n > 0) {
            count += (n / 5);
            n /= 5;
        }
        return count;
    }
};
// Time : O(logn)
// Space : O(1)