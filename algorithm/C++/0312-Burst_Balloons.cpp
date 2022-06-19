class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        
        for (int start = nums.size() - 2; start >= 1; --start) {
            for (int end = start; end <= nums.size() - 2; ++end) {
                for (int k=start; k <= end; ++k) {
                    dp[start][end] = max(dp[start][end], dp[start][k-1] + dp[k+1][end] + nums[start - 1] * nums[end + 1] * nums[k]);
                }
            }
        }
        return dp[1][nums.size() - 2];
    }
};
// Time : O(n^3)
// Space : O(n^2)