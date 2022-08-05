class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for (int i=0; i<columnTitle.size(); ++i) {
            ans += (columnTitle[i] - 'A' + 1);
            if (i != columnTitle.size() - 1) {
                ans *= 26;
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(1)