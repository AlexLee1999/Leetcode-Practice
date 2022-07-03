class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        int dp_2 = nums[0];
        int dp_1 = max(nums[0], nums[1]);
        for (int i=2; i<n; ++i) {
            int dp = max(dp_1, dp_2+ nums[i]);
            dp_2 = dp_1;
            dp_1 = dp;
        }
        return dp_1;
    }
};
// Time : O(n)
// Space : O(1)