class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int left = leftBound(nums, target);
        int right = rightBound(nums, target);
        int len = right - left + 1;
        return len > (nums.size() / 2);
    }
    int leftBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    int rightBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};
// Time : O(logn)
// Space : O(1)