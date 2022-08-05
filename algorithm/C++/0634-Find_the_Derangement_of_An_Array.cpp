class Solution {
public:
    int findDerangement(int n) {
        int mod = 1e9 + 7;
        // vector<long long> count(n + 1, 0);
        if (n == 1) {
            return 0;
        }
        // count[1] = 0;
        // count[2] = 1;
        // for (int i=3; i<=n; ++i) {
        //     count[i] = ((i - 1) * (count[i - 1] + count[i - 2])) % mod;
        // }
        long long count_2 = 0;
        long long count_1 = 1;
        for (int i=3; i<=n; ++i) {
            long long count = ((i - 1) * (count_1 + count_2)) % mod;
            count_2 = count_1;
            count_1 = count;
        }
        return count_1;
    }
};
// Time : O(n)
// Space : O(n)