class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long left = 0;
        long long right = 10000000;
        long long res = LLONG_MAX;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long left_res = tryCost(nums, cost, mid);
            long long right_res = tryCost(nums, cost, mid + 1);
            res = min(left_res, right_res);
            if (left_res < right_res) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
    long long tryCost(vector<int>& nums, vector<int>& cost, long long target) {
        long long res = 0;
        for (int i=0; i<nums.size(); ++i) {
            res += (long long)abs(nums[i] - target) * cost[i];
        }
        return res;
    }
};
// Time : O(nlogW)
// Space : O(1)