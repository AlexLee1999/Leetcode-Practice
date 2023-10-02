class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ways = 0;
        if (nums[0] > 0) {
            ways ++;
        }
        if (nums[n - 1] < n) {
            ways ++;
        }
        for (int i=0; i<n - 1; ++i) {
            if (i + 1 > nums[i] && i + 1 < nums[i + 1]) {
                ways ++;
            }
        }
        return ways;
    }
};