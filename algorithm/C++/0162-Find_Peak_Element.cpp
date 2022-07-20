class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 2;
        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else if (nums[mid] > nums[mid + 1]) {
                right = mid - 1;
            }
        }
        return left;
    }
};
// Time : O(logn)
// Space : O(1)