class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int cur_min = nums[0];
        int ans = -1;
        for (int i=1; i<nums.size(); ++i) {
            cur_min = min(cur_min, nums[i]);
            if (nums[i] > cur_min) {
                ans = max(ans, nums[i] - cur_min);
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(1)