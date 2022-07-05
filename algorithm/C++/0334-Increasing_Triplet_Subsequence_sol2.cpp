class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] <= first) {
                first = nums[i];
            } else if (nums[i] < second) {
                second = nums[i];
            } else if (nums[i] > second) {
                return true;
            }
        }
        return false;
    }
};
// Time : O(n)
// Space : O(1)