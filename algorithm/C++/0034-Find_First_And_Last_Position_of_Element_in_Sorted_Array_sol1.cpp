class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
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
        // left is the smallest index of targets
        // if left >= nums.size(), the number in nums is smaller than target
        if (left >= nums.size() || nums[left] != target) {
            return vector<int>{-1, - 1};
        }
        int pos = left;
        while (pos < nums.size() && nums[pos] == target) {
            pos ++;
        }
        return vector<int>{left, pos - 1};
    }
};
// Time : O(log(n))
// Space : O(1)
