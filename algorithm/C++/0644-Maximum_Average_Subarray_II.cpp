class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double left = *min_element(nums.begin(), nums.end());
        double right = *max_element(nums.begin(), nums.end());
        while (right - left > 0.00001) {
            double mid = left + (right - left) / 2.0;
            if (isPossible(nums, k, mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
    bool isPossible(vector<int>& nums, int k, double mid) {
        double sum = 0;
        double prev = 0;
        double min_sum = 0;
        for (int i=0; i<k; ++i) {
            sum += nums[i] - mid;
        }
        if (sum >= 0) {
            return true;
        }
        for (int i=k; i<nums.size(); ++i) {
            sum += nums[i] - mid;
            prev += nums[i - k] - mid;
            min_sum = min(min_sum, prev); // find the minimum sum before k element ==> the sum can exceed k elements
            if (sum >= min_sum) {
                return true;
            }
        }
        return false;
    }
};
// Time : O(nlogW)
// Space : O(1)