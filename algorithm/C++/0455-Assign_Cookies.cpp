class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int s_ptr = 0;
        int g_ptr = 0;
        while (s_ptr < s.size() && g_ptr < g.size()) {
            if (s[s_ptr] >= g[g_ptr]) {
                count ++;
                s_ptr ++;
                g_ptr ++;
            } else {
                s_ptr ++;
            }
        }
        return count;
    }
};
// Time : O(nlogn + mlogm)
// Space : O(m + m)