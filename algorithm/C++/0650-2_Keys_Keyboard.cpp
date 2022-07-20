class Solution {
public:
    int minSteps(int n) {
        vector<int> table(n + 1, 0);
        table[1] = 0;
        for (int i=2; i<=n; ++i) {
            table[i] = i;
            for (int j = 2; j < i; ++j) {
                if (i % j == 0) {
                    table[i] = min(table[i], table[j] + i / j);
                }
            }
        }
        return table[n];
    }
};
// Time : O(n^2)
// Space : O(n)