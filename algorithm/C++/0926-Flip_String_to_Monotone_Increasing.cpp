class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        right[n - 1] = (s[n - 1] == '0' ? 1 : 0);
        left[0] = (s[0] == '1' ? 1 : 0);
        for (int i=1; i<n; ++i) {
            left[i] = left[i - 1] + (s[i] == '1' ? 1 : 0);
        }
        for (int i=n - 2; i >= 0; --i) {
            right[i] = right[i + 1] + (s[i] == '0' ? 1 : 0);
        }
        int ans = INT_MAX;
        ans = min(ans, right[0]);
        for (int i=1; i<n; ++i) {
            ans = min(ans, left[i - 1] + right[i]);
        }
        ans = min(ans, left[n - 1]);
        return ans;
    }
};
// Time : O(n)
// Space : O(n)