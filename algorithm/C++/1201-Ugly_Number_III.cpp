class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int left = 1;
        int right = INT_MAX;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long num = calculateNum(mid, a, b, c);
            if (num >= n) {
                right = mid - 1;
            } else if (num < n) {
                left = mid + 1;
            }
        }
        return left;
    }
    long long calculateNum(long long n, long long a, long long b, long long c) {
        return n/a + n/b + n/c - n/lcm(a, b) - n/lcm(b, c) - n/lcm(a, c) + n/lcm(a, lcm(b, c));
    }
    long long gcd(long long a, long long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    long long lcm (long long a, long long b) {
        return a * b / gcd(a, b);
    }
};
// Time : O(logk)
// Space : O(1)