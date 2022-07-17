class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> table(5, 1);
        for (int j=2; j<=n; ++j) {
            int a = table[0] * 1;
            int e = table[1] + table[0];
            int i = table[2] + table[1] + table[0];
            int o = table[3] + table[2] + table[1] + table[0];
            int u = table[4] + table[3] + table[2] + table[1] + table[0];
            table[0] = a;
            table[1] = e;
            table[2] = i;
            table[3] = o;
            table[4] = u;
        }
        return table[4] + table[3] + table[2] + table[1] + table[0];
    }
};
// Time : O(n)
// Space : O(1)