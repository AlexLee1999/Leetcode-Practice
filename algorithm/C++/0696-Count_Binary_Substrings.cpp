class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int prev = 0;
        int cur = 1;
        for (int i=1; i<s.size(); ++i) {
            if (s[i] != s[i - 1]) {
                ans += min(cur, prev);
                prev = cur;
                cur = 1;
            } else {
                cur ++;
            }
        }
        ans += min(cur, prev);
        return ans;
    }
};
// Time : O(n)
// Space : O(1)