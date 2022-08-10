class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> table(n + 1, vector<int>(5, 0));
        int mod = 1e9 + 7;
        for (int i=0; i<5; ++i) {
            table[1][i] = 1;
        }
        for (int i=2; i<=n; ++i) {
            // a
            table[i][0] = (table[i][0] + table[i - 1][1]) % mod;// ea
            table[i][0] = (table[i][0] + table[i - 1][2]) % mod;// ia
            table[i][0] = (table[i][0] + table[i - 1][4]) % mod;// ua
            // e
            table[i][1] = (table[i][1] + table[i - 1][0]) % mod;// ae
            table[i][1] = (table[i][1] + table[i - 1][2]) % mod;// ie
            // i
            table[i][2] = (table[i][2] + table[i - 1][1]) % mod;// ei
            table[i][2] = (table[i][2] + table[i - 1][3]) % mod;// oi
            // o
            table[i][3] = (table[i][3] + table[i - 1][2]) % mod;// io
            // u
            table[i][4] = (table[i][4] + table[i - 1][2]) % mod;// iu
            table[i][4] = (table[i][4] + table[i - 1][3]) % mod;// ou
        }
        int ans = 0;
        for (int i=0; i<5; ++i) {
            ans = (ans + table[n][i]) % mod;
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)