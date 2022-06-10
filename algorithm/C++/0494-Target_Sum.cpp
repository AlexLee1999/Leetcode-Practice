class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
        }
        if (target > 0 && target > sum) {
            return 0;
        }
        if (target < 0 && target < -1 * sum) {
            return 0;
        }
        vector<vector<int>> table(nums.size(), vector<int>(2*sum + 1, 0));
        table[0][sum + nums[0]] ++;
        table[0][sum - nums[0]] ++;
        for (int i=1; i<nums.size(); ++i) {
            for (int j = -1 * sum; j <= sum; ++j) {
                if (table[i-1][j + sum] > 0) {
                    table[i][j + sum + nums[i]] += table[i-1][j + sum];
                    table[i][j + sum - nums[i]] += table[i-1][j + sum];
                }
            }
        }
        return table[nums.size() - 1][target + sum];
    }
};
// Time : O(tn)
// Space : O(tn) t is the target