class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        constexpr int mod = 1e9 + 7;
        for (int i=1; i<nums.size(); ++i) {
            nums[i] += nums[i - 1];
        }
        long long count = 0;
        for (int i=0; i<nums.size(); ++i) {
            int left = lower_bound(nums.begin() + i + 1, nums.end(), 2 * nums[i]) - nums.begin();
            int right = upper_bound(nums.begin(), nums.end() - 1, (nums[n - 1] - nums[i]) / 2 + nums[i]) - nums.begin();
            // Possible range is [left ~ right - 1]
            if (right > left) {
                count += (right - 1 - left + 1);
            }
        }
        return count % mod;
    }
};
// Time : O(nlogn)
// Space : O(n)