class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        quickselect(nums, k, 0, n - 1);
        return nums[n - k];
    }
    void quickselect(vector<int>& nums, int k, int low, int high) {
        if (low < high) {
            int pivot = partition(nums, low, high);
            if (pivot == nums.size() - k) {
                return;
            }
            if (pivot < nums.size() - k) {
                quickselect(nums, k, pivot + 1, high);
            } else {
                quickselect(nums, k, low, pivot - 1);
            }
            
        }
    }
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int idx = low - 1;
        for (int i=low; i<high; ++i) {
            if (nums[i] <= pivot) {
                idx ++;
                swap(nums[i], nums[idx]);
            }
        }
        swap(nums[high], nums[idx + 1]);
        return idx + 1;
    }
};
// Time : O(n)
// Space : O(n)