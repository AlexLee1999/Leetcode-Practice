class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int max_number = *max_element(nums.begin(), nums.end());
        vector<int> count (max_number + 1, 0);
        for (int i=0; i<nums.size(); ++i) {
            count[nums[i]] += nums[i];
        }
        int n = count.size();
        if (n == 1) {
            return count[0];
        }
        if (n == 2) {
            return max(count[0], count[1]);
        }
        vector <int> dp (n, 0);
        dp[0] = count[0];
        dp[1] = max(count[0], count[1]);
        for (int i=2; i<n; ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + count[i]);
        }
        return dp[n-1];
    }
};