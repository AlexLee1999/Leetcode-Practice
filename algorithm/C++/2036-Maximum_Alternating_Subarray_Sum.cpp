class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> odd = nums;
        vector<int> even = nums;
        for (int i=0; i<nums.size(); ++i) {
            if (i % 2 == 1) {
                odd[i] *= -1;
            } else {
                even[i] *= -1;
            }
        }
        vector<long long> table(nums.size(), INT_MIN);
        long long ans = nums[0];
        table[0] = nums[0];
        for (int i=1; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                table[i] = (table[i - 1] > 0) ? table[i - 1] + odd[i] : odd[i];
            } else {
                table[i] = table[i - 1] + odd[i];
            }
            ans = max(ans, table[i]);
        }
        table = vector<long long>(nums.size(), INT_MIN);
        table[1] = nums[1];
        ans = max(ans, table[1]);
        for (int i=2; i < nums.size(); ++i) {
            if (i % 2 == 1) {
                table[i] = (table[i - 1] > 0) ? table[i - 1] + even[i] : even[i];
            } else {
                table[i] = table[i - 1] + even[i];
            }
            ans = max(ans, table[i]);
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)