class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1e9 + 7;
        char prev = s[0];
        long long count = 0;
        int prev_idx = 0;
        for (int i=1; i<=s.size(); ++i) {
            if (i == s.size() || s[i] != prev) {
                int len = i - prev_idx;
                count += ((long long)(len + 1) * (long long)len / 2);
                count %= mod;
                prev = s[i];
                prev_idx = i;
            } else {
                continue;
            }
        }
        count %= mod;
        return (int) count;
    }
};
// Time : O(n)
// Space : O(n)