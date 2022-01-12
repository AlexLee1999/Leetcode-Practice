class Solution {
public:
    int modPow(int a, int pow) {
        int res = 1;
        int base = a;
        while (pow > 0) {
            if (pow & 1) {
                res *= base;
                res % 1337;
            }
            base = base * base;
            base %= 1337;
            pow >>= 1;
        }
        return res % 1337;
    }
    int superPow(int a, vector<int>& b) {
        int n = b.size();
        a %= 1337;
        int res = 1;
        int base = a;
        int originBase = a;
        for (int i = n - 1; i >= 0; --i) {
            res *= modPow(base, b[i]);
            originBase = base;
            res %= 1337;
            base = base * base;
            base %= 1337;
            base = base * base;
            base %= 1337;
            base = base * base;
            base %= 1337;
            base = base * originBase * originBase;
            base %= 1337;
        }
        return res;
    }
};
