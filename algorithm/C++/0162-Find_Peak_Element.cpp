class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1; // [left, right)
        while (left < right) {
            int mid = left + (right-left) / 2;
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else if (nums[mid] > nums[mid + 1]) {
                right = mid;
            }
        }
        return left;
    }
};