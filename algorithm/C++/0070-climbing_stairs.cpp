class Solution {
public:
    int climbStairs(int n) {
        vector<int> table(n, 1);
        if (n == 1) {
            return 1;
        }
        table[1] = 2;
        for (int i = 2; i < n; ++i) {
            table[i] = table[i-1] + table[i-2];
        }
        return table[n-1];
    }
};
