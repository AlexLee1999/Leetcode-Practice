class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        vector<vector<int>> table(nums.size(), vector<int>(2, 0));
        table[0][0] = nums[0];
        table[0][1] = nums[0] * nums[0];
        int max_sum = max(table[0][0], table[0][1]);
        for (int i=1; i<nums.size(); ++i) {
            table[i][0] += (table[i-1][0] > 0) ? table[i-1][0] + nums[i] : nums[i];
            int tmp1 = (table[i-1][1] > 0) ? table[i-1][1] + nums[i] : nums[i];
            int tmp2 = (table[i-1][0] > 0) ? table[i-1][0] + nums[i] * nums[i] : nums[i] * nums[i];
            table[i][1] = max(tmp1, tmp2);
            max_sum = max(max_sum, max(table[i][0], table[i][1]));
        }
        return max_sum;
    }
};
// Time : O(n)
// Space : O(n)