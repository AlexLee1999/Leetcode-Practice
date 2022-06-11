class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k == 1) {
            return 1;
        }
        int res = 0;
        for (int i=1; i<=k; ++i) {
            res *= 10;
            res ++;
            res %= k;
            if (res == 0) {
                return i;
            }
        }
        return -1;
    }
};
// Time : O(k)
// Space : O(1)