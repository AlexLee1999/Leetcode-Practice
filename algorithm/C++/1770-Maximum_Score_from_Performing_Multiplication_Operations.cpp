class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> table(m + 1, vector<int>(m + 1, 0));
        for (int k=1; k<=m; ++k) {
            int i = 0;
            int j = k - i;
            while (i <= k) {
                if (i == 0) {
                    table[i][j] = table[i][j - 1] + nums[n - j] * multipliers[k - 1];
                } else if (j == 0) {
                    table[i][j] = table[i - 1][j] + nums[i - 1] * multipliers[k - 1];
                } else {
                    table[i][j] = max(table[i - 1][j] + nums[i - 1] * multipliers[k - 1], table[i][j - 1] + nums[n - j] * multipliers[k - 1]);
                }
                i ++;
                j --;
            }
        }
        int ans = INT_MIN;
        for (int i=0; i<=m; ++i) {
            ans = max(ans, table[i][m - i]);
        }
        return ans;
    }
};
// Time : O(m^2)
// Space ; O(m^2)