class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long min_idx = -1;
        long long max_idx = -1;
        long long ans = 0;
        long long idx = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] > maxK || nums[i] < minK) {
                idx = i + 1;
                min_idx = -1;
                max_idx = -1;
                continue;
            }
            if (nums[i] == maxK) {
                max_idx = i;
            }
            if (nums[i] == minK) {
                min_idx = i;
            }
            ans += max(0LL, min(min_idx, max_idx) - idx + 1);
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(1)