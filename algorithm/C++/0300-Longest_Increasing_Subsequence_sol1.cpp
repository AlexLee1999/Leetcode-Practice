class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, 1);
        for (int i=1; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int max_length = 0;
        for (int i=0; i<n; ++i) {
            max_length = max(max_length, dp[i]);
        }
        return max_length;
    }
};