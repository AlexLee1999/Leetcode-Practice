class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> table (n, 0);
        table[0] = nums[0];
        int max_num = table[0];
        for (int i = 1; i < n; ++i) {
            table[i] += ((table[i-1] > 0) ? table[i-1] + nums[i] : nums[i]);
            max_num = max(table[i], max_num);
        }
        return max_num;
    }
};
