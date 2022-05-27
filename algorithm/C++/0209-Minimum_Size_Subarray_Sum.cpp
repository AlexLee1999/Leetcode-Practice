class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        
        for (int i=1; i<=nums.size(); ++i) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        if (sum[n] < target) {
            return 0;
        }
        int left = 1;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(target, nums, mid, sum)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left; // right = left - 1
    }
    bool isPossible(int target, vector<int>& nums, int mid, vector<int>& sum) {
        for (int i=0; i<=nums.size()-mid; ++i) {
            int diff = sum[i + mid] - sum[i];
            if (diff >= target) {
                return true;
            }
        }
        return false;
    }
};