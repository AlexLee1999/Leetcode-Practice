class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> table(26, 0);
        for (int i=0; i<s.size(); ++i) {
            int cur_len = table[s[i] - 'a'];
            for (int j=-k; j<=k; ++j) {
                int cur = s[i] - 'a' + j;
                if (cur > 25 || cur < 0) {
                    continue;
                }
                if (j == 0) {
                    table[s[i] - 'a'] = max(cur_len + 1, table[s[i] - 'a']);
                } else {
                    table[s[i] - 'a'] = max(table[s[i] - 'a'], table[cur] + 1);
                }
            }
        }
        int max_len = 0;
        for (int i=0; i<26; ++i) {
            max_len = max(max_len, table[i]);
        }
        return max_len;
    }
};
// Time : O(kn)
// Space : O(1)