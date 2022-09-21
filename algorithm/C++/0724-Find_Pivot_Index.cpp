class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivot = -1;
        int sum = 0;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
        }
        int left = 0;
        int right = sum;
        for (int i=0; i<nums.size(); ++i) {
            right -= nums[i];
            if (left == right) {
                pivot = i;
                return pivot;
            }
            left += nums[i];
        }
        return pivot;
    }
};
// Time : O(n)
// Space : O(1)