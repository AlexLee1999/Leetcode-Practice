class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = nums[0];
        int max_num = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            int cur = 0;
            if (prev <= 0) {
                cur = nums[i];
            } else {
                cur = nums[i] + prev;
            }
            max_num = max(max_num, cur);
            prev = cur;
        }
        return max_num;
    }
};
// Time : O(n)
// Space : O(1)