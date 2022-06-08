class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        int pre = nums[0];
        int count = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != pre) {
                pre = nums[i];
                nums[count] = nums[i];
                ++count;
            }
        }
        return count;
    }
};
// Time : O(n)
// Space : O(1)