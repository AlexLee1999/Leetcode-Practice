class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 1) {
            return 0;
        }
        int ans = nums.back() - nums[0];
        for (int i=0; i<nums.size() - 1; ++i) {
            int cur_min = min(nums[i + 1] - k, nums[0] + k); // The possible minimum value is nums[i + 1] - k
            int cur_max = max(nums[i] + k, nums.back() - k);
            ans = min(ans, cur_max - cur_min);
        }
        return ans;
    }
};
// Time : O(nlogn)
// Space : O(1)