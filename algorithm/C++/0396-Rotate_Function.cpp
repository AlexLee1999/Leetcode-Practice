class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int func = 0;
        for (int i=0; i<n; ++i) {
            sum += nums[i];
            func += i * nums[i];
        }
        int ans = func;
        for (int i=0; i<n - 1; ++i) {
            func += sum - nums[n - 1 - i] * n;
            ans = max(ans, func);
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(1)