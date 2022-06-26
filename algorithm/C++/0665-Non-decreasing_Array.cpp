class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int index = -1;
        for (int i=0; i<nums.size() - 1; ++i) {
            if (nums[i] > nums[i+1]) {
                if (index != -1) {
                    return false;
                } else {
                    index = i;
                }
            }
        }
        
        if (index < 1 || index == nums.size() - 2 || nums[index - 1] <= nums[index + 1] || nums[index] <= nums[index + 2]) {
            // if nums[index - 1] <= nums[index + 1], change nums[index] to nums[index - 1] ~ nums[index + 1]
            // if nums[index] <= nums[index + 2], change nums[index + 1] to nums[index] ~ nums[index + 2]
            return true;
        }
        return false;
    }
};
// Time : O(n)
// Space : O(1)