class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        int max_average = 0;
        for (int i=0; i<n; ++i) {
            sum += nums[i];
            int avg = sum / (long long)(i + 1) + (sum % (i + 1) != 0);
            max_average = max(max_average, avg);
        }
        return max_average;
    }
};