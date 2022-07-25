class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int max_num = 0;
        while (left < right) {
            if (nums[left] + nums[right] < k) {
                max_num = max(max_num, nums[left] + nums[right]);
                left ++;
            } else {
                right --;
            }
        }
        return max_num == 0 ? -1 : max_num;
    }
};
// Time : O(nlogn)
// Space : O(1)