class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] - mid - nums[0] < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return nums[right] + k - (nums[right] - right - nums[0]);
    }
};
// Time : O(logn)
// Space : O(1)