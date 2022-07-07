class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) {
            return 0;
        }
        int count = 0;
        vector<bool> table(n, false);
        int sqrt_n = (int)ceil(sqrt(n));
        for (int i = 2; i<sqrt_n; ++i) {
            if (table[i] == false) {
                for (int j = 2 * i; j < n; j += i) {
                    table[j] = true;
                }
            }
        }
        for (int i=2; i<n; ++i) {
            count += !(table[i]);
        }
        return count;
    }
};
// Time : O(sqrt(n)loglogn + n)
// Space : O(n)