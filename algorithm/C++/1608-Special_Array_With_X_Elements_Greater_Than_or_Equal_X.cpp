class Solution {
public:
    int specialArray(vector<int>& nums) {
        int left = 0;
        int right = nums.size(); // the maximum number that is larger than x is nums.size()
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid > countLarger(nums, mid)) {
                right = mid - 1;
            } else if (mid < countLarger(nums, mid)) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
    int countLarger(vector<int>& nums, int mid) {
        int count = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] >= mid) {
                count ++;
            }
        }
        return count;
    }
};
// Time : O(nlogn)
// Space : O(1)