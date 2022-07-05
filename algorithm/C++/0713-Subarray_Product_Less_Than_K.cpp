class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int prod = 1;
        int count = 0;
        for (int right = 0; right < nums.size(); ++right) {
            prod *= nums[right];
            while (prod >= k && left <= right) {
                prod /= nums[left];
                left ++;
            }
            count += (right - left + 1); // All subarray between [left~right - right] is valid
        }
        return count;
    }
};
// Time : O(n)
// Space : O(1)