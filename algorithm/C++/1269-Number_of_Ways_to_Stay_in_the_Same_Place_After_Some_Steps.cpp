class Solution {
public:
    int numWays(int steps, int arrLen) {
        if (arrLen == 1) {
            return 1;
        }
        int max_step = min(arrLen - 1, steps);
        vector<long long> table(max_step + 1, 0);
        int mod = 1e9 + 7;
        table[0] = 1;
        for (int i=1; i<=steps; ++i) {
            vector<long long> tmp(max_step + 1, 0);
            for (int j=0; j<=max_step; ++j) {
                if (j == max_step) {
                    tmp[j] = (table[j] + table[j - 1]) % mod;
                } else if (j == 0) {
                    tmp[j] = (table[j] + table[j + 1]) % mod;
                } else {
                    tmp[j] = (table[j] + table[j - 1] + table[j + 1]) % mod;
                }
            }
            table = tmp;
        }
        return table[0] % mod;
    }
};
// Time : O(nS)
// Space : O(n)