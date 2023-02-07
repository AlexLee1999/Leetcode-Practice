class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = 0;
        int right = (int)1e9;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if(isPossible(nums, mid, k)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool isPossible(vector<int>& nums, int capacity, int k) {
        int i = 0;
        int count = 0;
        while (i < nums.size()) {
            if (nums[i] <= capacity) {
                i += 2;
                count ++;
            } else {
                i ++;
            }
        }
        return count >= k;
    }
};
// Time : O(nlogm)
// Space : O(1)