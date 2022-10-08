class Solution {
public:
    long long appealSum(string s) {
        vector<int> prev(26, -1);
        long long ans = 0;
        long long cur = 0;
        for (int i=0; i<s.size(); ++i) {
            cur += i - prev[s[i] - 'a'];
            prev[s[i] - 'a'] = i;
            ans += cur;
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(1)