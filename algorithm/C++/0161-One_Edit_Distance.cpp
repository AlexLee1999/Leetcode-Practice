class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (s == "" && t == "") {
            return false;
        }
        if (m > n) {
            return isOneEditDistance(t, s);// assume t is longer than s
        }
        if ((n - m) > 1) {
            return false;
        }
        for (int i=0; i<n; ++i) {
            if (s[i] != t[i]) {
                if (m == n) {
                    return t.substr(i + 1, n - 1 - i) == s.substr(i + 1, m - 1 - i);
                } else if (m == (n - 1)) {
                    return t.substr(i + 1, n - 1 - i) == s.substr(i, m - i);
                }
            }
        }
        return false;
    }
};
// Time : O(n)
// Space : O(n) substr uses O(n) space