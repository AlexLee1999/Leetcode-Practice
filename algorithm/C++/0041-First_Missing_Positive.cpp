class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == INT_MIN) {
                ++i;
                continue;
            }
            int j = nums[i] - 1;
            if (j >= 0 && j < n && nums[i] != nums[j]) {
                swap(nums[i], nums[j]);
            }
            else {
                ++i;
            }
        }
        for (int i=0; i<n; ++i) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        return nums.size() + 1;
    }
};