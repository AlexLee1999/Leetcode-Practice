class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<int> prev(n, -1);
        vector<int> next(n, n);
        vector<int> index(26, -1); // for all index, find the prev and next index that has the same character
        for (int i=0; i<n; ++i) {
            int idx = s[i] - 'A';
            prev[i] = index[idx];
            index[idx] = i;
        }
        index = vector<int>(26, n);
        for (int i=n - 1; i>= 0; --i) {
            int idx = s[i] - 'A';
            next[i] = index[idx];
            index[idx] = i;
        }
        int ans = 0;
        for (int i=0; i<n; ++i) {
            ans += (i - prev[i]) * (next[i] - i);
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)