class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ans = s;
        if (k == 1) {
            for (int i=0; i<s.size(); ++i) {
                s = s.substr(1) + s[0];
                if (s < ans) {
                    ans = s;
                }
            }
            return ans;
        }
        sort(s.begin(), s.end());
        return s;
    }
};
// Time : O(n^2)
// Space : O(n)