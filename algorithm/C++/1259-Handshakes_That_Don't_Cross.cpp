class Solution {
public:
    int numberOfWays(int numPeople) {
        int mod = 1e9 + 7;
        vector<long long> table(numPeople + 1, 0);
        table[0] = 1;
        for (int i=2; i<=numPeople; i += 2) {
            for (int j=0; j<=i - 2; j += 2) {
                table[i] = (table[i] + table[j] * table[i - 2 - j]) % mod;
            }
        }
        return table[numPeople] % mod;
    }
};