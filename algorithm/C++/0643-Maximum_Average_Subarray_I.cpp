class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int max_sum = INT_MIN;
        int cur_sum = 0;
        for (int i=0; i<n; ++i) {
            cur_sum += nums[i];
            if (i == k-1) {
                max_sum = max(max_sum, cur_sum); // Corner case; k == nums.size()-1
            }
            if (i >= k) {
                cur_sum -= nums[i-k];
                max_sum = max(max_sum, cur_sum);
            }
        }
        return (double)max_sum / (double)k;
    }
};
// Time : O(n)
// Space : O(1)