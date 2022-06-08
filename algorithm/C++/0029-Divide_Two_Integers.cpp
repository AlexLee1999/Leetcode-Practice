class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == divisor) {
            return 1;
        }
        if (divisor == -1) {
            return dividend - dividend - dividend;
        }
        if (divisor == 1) {
            return dividend;
        }
        long un_dividend = abs(dividend);
        long un_divisor = abs(divisor);
        bool sign_dividend = dividend < 0 ? true : false;
        bool sign_divisor = divisor < 0 ? true : false;
        int ans = 0;
        while (un_dividend >= un_divisor) {
            long val = un_divisor;
            long count = 1;
            while ((val << 1) <= un_dividend) {
                val = val << 1;
                count = count << 1;
            }
            un_dividend -= val;
            ans += count;
        }
        if (sign_dividend ^ sign_divisor) {
            return ans - ans - ans;
        }
        return ans;
    }
};
// Time : O(log^2(n))
// Space : O(1)