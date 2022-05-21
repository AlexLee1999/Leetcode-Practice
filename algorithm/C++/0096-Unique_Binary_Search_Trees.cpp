class Solution {
public:
    int numTrees(int n) {
        vector<int> table(n + 1);
        table[0] = 1;
        table[1] = 1;
        for (int i=2; i<=n; ++i) {
            for (int j=1; j<=i; ++j) {
                table[i] += table[j - 1] * table[i-j];
            }
        }
        return table[n];
    }
};