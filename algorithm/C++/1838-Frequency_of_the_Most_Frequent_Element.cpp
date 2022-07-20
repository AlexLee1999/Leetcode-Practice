class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        long long sum = 0;
        int max_len = 0;
        for (right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            while ((long long)nums[right] * (right - left + 1) - sum > k) {
                sum -= nums[left];
                left ++;
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};
// Time : O(nlogn)
// Space : O(1)
/* Idea : Find the maximum sliding window that nums[right] * (right - left + 1) - sum <= k */