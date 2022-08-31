class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> table(n + 1, false);
        if (n == 1) {
            return false;
        }
        table[0] = true;
        table[1] = false;
        table[2] = (nums[0] == nums[1]);
        for (int i=3; i<=n; ++i) {
            if (nums[i - 1] == nums[i - 2]) {
                table[i] = table[i] | table[i - 2];
            }
            if (nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3]) {
                table[i] = table[i] | table[i - 3];
            }
            if (nums[i - 1] == nums[i - 2] + 1 && nums[i - 2] == nums[i - 3] + 1) {
                table[i] = table[i] | table[i - 3];
            }
        }
        return table[n];
    }
};
// Time : O(n)
// Space : O(n)