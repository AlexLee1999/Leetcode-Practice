class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1e9 + 7;
        long long ans = 1;
        for (int i=2; i<=n; ++i) {
            int digit = log2(i) + 1;
            ans <<= digit;
            ans += i;
            ans %= mod;
        }
        return (int)ans;
    }
};
// Time : O(n)
// Space : O(1)