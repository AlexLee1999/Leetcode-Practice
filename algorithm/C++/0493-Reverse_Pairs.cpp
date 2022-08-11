class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        mergeSort(nums, 0, nums.size() - 1, count);
        return count;
    }
    void mergeSort(vector<int>& nums, int left, int right, int& count) {
        if (left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid, count);
        mergeSort(nums, mid + 1, right, count);
        merge(nums, left, mid, right, count);
    }
    void merge(vector<int>& nums, int left, int mid, int right, int& count) {
        int left_ptr = left;
        int right_ptr = mid + 1;
        int j = mid + 1;
        for (int i=left; i<=mid; ++i) {
            while (j <= right && nums[i] <= (long long)2 * nums[j]) {
                j ++;
            }
            count += (right - j + 1);
        }
        vector<int> tmp(right - left + 1, 0);
        int tmp_ptr = 0;
        while (left_ptr <= mid && right_ptr <= right) {
            if (nums[left_ptr] > nums[right_ptr]) {
                tmp[tmp_ptr] = nums[left_ptr];
                tmp_ptr ++;
                left_ptr ++;
            } else {
                tmp[tmp_ptr] = nums[right_ptr];
                tmp_ptr ++;
                right_ptr ++;
            }
        }
        while (left_ptr <= mid) {
            tmp[tmp_ptr] = nums[left_ptr];
            tmp_ptr ++;
            left_ptr ++;
        }
        while (right_ptr <= right) {
            tmp[tmp_ptr] = nums[right_ptr];
            tmp_ptr ++;
            right_ptr ++;
        }
        for (int i=left; i<=right; ++i) {
            nums[i] = tmp[i - left];
        }
    }
};
// Time : O(nlogn)
// Space : O(n)