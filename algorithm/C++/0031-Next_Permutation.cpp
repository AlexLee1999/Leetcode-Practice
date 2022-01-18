class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (i < 0) { // no next pernutation, reverse the string
            reverse(nums.begin(), nums.end());
        } else {
            for (int j = nums.size() - 1; j > i; j --) {
                if (nums[i] < nums[j]) { // find the nums[j] that is the smallest larger number than nums[i] 
                    swap(nums[i], nums[j]);
                    reverse(nums.begin() + i + 1, nums.end());
                    break;
                }
            }
        }
    }
};