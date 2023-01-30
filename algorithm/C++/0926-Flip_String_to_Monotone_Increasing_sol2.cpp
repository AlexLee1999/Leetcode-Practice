class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int num = 0;
        int n = s.size();
        vector<int> table(n + 1, 0);
        for (int i=0; i<n; ++i) {
            if (s[i] == '1') {
                num ++;
                table[i + 1] = table[i];
            } else {
                table[i + 1] = min(num, table[i] + 1);
            }
        }
        return table[n];
    }
};
// Time : O(n)
// Space : O(n)