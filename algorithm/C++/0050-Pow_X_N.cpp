class Solution {
public:
    double myPow(double x, int n) {
        bool sign = false;
        double ans = 1.0;
        long newN = n;
        if (n < 0) {
            newN = (-1) * newN;
            sign = true;
        }
        double base = x;
        while (newN > 0) {
            if (newN & 1) {
                ans *= base;
            }
            base = base * base;
            newN >>= 1;
        }
        return sign ? (1.0 / ans): ans;
    }
};
