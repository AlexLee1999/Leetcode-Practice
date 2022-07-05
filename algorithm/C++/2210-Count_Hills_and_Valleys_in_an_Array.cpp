class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        for (int i=1; i<nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] = nums[i-1];
            }
            if (nums[i] < nums[i + 1] && nums[i - 1] > nums[i]) {
                count ++;
            }
            if (nums[i] > nums[i + 1] && nums[i - 1] < nums[i]) {
                count ++;
            }
        }
        return count;
    }
};
// Time : O(n)
// Space : O(1)