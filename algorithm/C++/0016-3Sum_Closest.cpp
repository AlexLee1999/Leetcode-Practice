class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int tmpSum;
        int left;
        int right;
        int gap = INT_MAX;
        int res;
        for (int i = 0; i < n; ++i) {
            left = i + 1;
            right = n - 1;
            while (left < right) {
                tmpSum = nums[i] + nums[left] + nums[right];
                if (gap > abs(tmpSum - target)) {
                    gap = abs(tmpSum - target);
                    res = tmpSum;
                }
                if (tmpSum > target) {
                    --right;
                }
                else {
                    ++left;
                }
            }
        }
        return res;
    }
};
// Time : O(n^2)
// Space : O(log(n)) ~ O(n) base on sorting algorithms