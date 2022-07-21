class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int table_0_1 = nums[0];
        int table_1_1 = nums[0] * nums[0];
        int max_sum = max(table_0_1, table_1_1);
        for (int i=1; i<nums.size(); ++i) {
            int table_0 = 0;
            int table_1 = 0;
            table_0 += (table_0_1 > 0) ? table_0_1 + nums[i] : nums[i];
            int tmp1 = (table_1_1 > 0) ? table_1_1 + nums[i] : nums[i];
            int tmp2 = (table_0_1 > 0) ? table_0_1 + nums[i] * nums[i] : nums[i] * nums[i];
            table_1 = max(tmp1, tmp2);
            max_sum = max(max_sum, max(table_0, table_1));
            table_0_1 = table_0;
            table_1_1 = table_1;
        }
        return max_sum;
    }
};
// Time : O(n)
// Space : O(1)