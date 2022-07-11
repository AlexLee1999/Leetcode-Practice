class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        long long prefix = 0;
        long long total = 0;
        for (int i=0; i<nums.size(); ++i) {
            total += nums[i];
        }
        for (int i=0; i<n - 1; ++i) {
            prefix += nums[i];
            if (prefix >= (total - prefix)) {
                count ++;
            }
        }
        return count;
    }
};
// Time : O(n)
// Space : O(1)