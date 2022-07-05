class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() < 3) {
            return true;
        }
        bool increasing = false;
        bool decreasing = false;
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i] - nums[i-1] > 0) {
                increasing = true;
            }
            if (nums[i] - nums[i-1] < 0) {
                decreasing = true;
            }
        }
        return !(increasing && decreasing);
    }
};
// Time : O(N)
// Space : O(1)