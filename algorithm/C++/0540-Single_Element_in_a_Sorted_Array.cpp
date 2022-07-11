class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } 
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid & 1 == 1) { // Claim : the single number has even index
                mid --;
            }
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            } else {
                right = mid - 2;
            }
        }
        return nums[left];
    }
};
// Time : O(logn)
// Space : O(1)