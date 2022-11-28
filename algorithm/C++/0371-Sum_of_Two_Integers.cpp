class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0) {
            return b;
        }
        if (b == 0) {
            return a;
        }
        int carry;
        while (b != 0) {
            carry = a & b;
            a ^= b;
            b = (unsigned)carry << 1;
        }
        return a;
    }
};
// Time : O(min(log(a), log(b)))
// Space : O(1)