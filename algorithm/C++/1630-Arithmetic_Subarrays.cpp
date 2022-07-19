class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size(), false);
        for (int i=0; i<l.size(); ++i) {
            vector<int> tmp(nums.begin() + l[i], nums.begin() + r[i] + 1);
            if (isArithmetic(tmp)) {
                ans[i] = true;
            }
        }
        return ans;
    }
    bool isArithmetic(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 2) {
            return true;
        }
        for (int i=1; i<nums.size() - 1; ++i) {
            if (nums[i] - nums[i - 1] != nums[i + 1] - nums[i]) {
                return false;
            }
        }
        return true;
    }
};
// Time : O(knlogn)
// Space : O(1)