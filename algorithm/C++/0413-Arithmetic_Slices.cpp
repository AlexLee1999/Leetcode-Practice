class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int> table(n, 0);
        for (int i=2; i<n; ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                table[i] = table[i - 1] + 1;
                sum += table[i];
            }
        }
        return sum;
    }
};
// Time : O(n)
// Space : O(n)