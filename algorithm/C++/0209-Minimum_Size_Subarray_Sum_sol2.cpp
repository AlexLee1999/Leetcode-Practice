class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int min_len = INT_MAX;
        int sum = 0;
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            while (sum >= target) {
                min_len = min(min_len, right - left + 1);
                sum -= nums[left];
                left ++;
            }
        }
        return (min_len == INT_MAX) ? 0 : min_len;
    }
};
// Time : O(n)
// Space : O(1)