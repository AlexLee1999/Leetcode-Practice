class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.insert(nums.begin(), 0);
        long long ans = 0;
        for (int i=0; i<nums.size() - 1; ++i) {
            if (k > 0) {
                int diff = nums[i + 1] - nums[i] - 1;
                if (diff <= 0) {
                    continue;
                }
                if (diff > k) {
                    ans += (((long long)(nums[i] + 1 + nums[i] + k) * k) / 2);
                    k = 0;
                } else {
                    ans += (((long long)(nums[i] + 1 + nums[i] + diff) * diff) / 2);
                    k -= diff;
                }
            }
        }
        if (k > 0) {
            ans += (((long long)(nums.back() + 1 + nums.back() + k) * k) / 2);
        }
        return ans;
    }
};
// Time : O(nlogn)
// Space : O(1)