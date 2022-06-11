class Solution {
public:
    int numWays(int n, int k) {
        vector<int> table(n + 1, 0);
        table[1] = k;
        if (n >= 2) {
            table[2] = k * k;
        }
        for (int i=3; i<=n; ++i) {
            table[i] = (k-1) * table[i-1] + (k-1) * table[i-2];
        }
        return table[n];
    }
};
// Time : O(n)
// Space : O(n)
// if ith and i-1th fences have the same color, i-2th has to be different with i-1th
// therefore, there will be (k-1) * table[i-2] ways
// if ith and i-1th fences have different color, there are (k-1) * table[i-1] different ways