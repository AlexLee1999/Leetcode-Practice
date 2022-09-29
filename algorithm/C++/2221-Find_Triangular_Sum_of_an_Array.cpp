class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> tmp(nums.size(), 0);
        for (int j=0; j<nums.size() - 1; ++j) {
            for (int i=0; i<nums.size() - 1; ++i) {
                tmp[i] = (nums[i] + nums[i + 1]) % 10;
            }
            nums = tmp;
        }
        return nums[0];
    }
};
// Time : O(n^2)
// Space : O(n)