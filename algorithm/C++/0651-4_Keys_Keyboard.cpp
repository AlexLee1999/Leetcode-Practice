class Solution {
public:
    int maxA(int n) {
        vector<int> table(n + 1, 0);
        table[1] = 1;
        for (int i=2; i <= n; ++i) {
            table[i] = table[i-1] + 1;
            for (int j=1; j <= i - 3; ++j) { // i - 3 => needs at least three operations (Select, Copy, and Paste)
                table[i] = max(table[i], table[j] * (i - j - 1));
            }
        }
        return table[n];
    }
};
// Time : O(n^2)
// Space : O(n)