class Solution {
public:
    int integerBreak(int n) {
        vector<int> table(n + 1, 1);
        for (int i=3; i<=n; ++i) {
            for (int j = 1; j < i; ++j) {
                table[i] = max(table[i], max(j * (i - j), table[i-j] * j));
            }
        }
        return table[n];
    }
};
// Time : O(n)
// Space : O(n)