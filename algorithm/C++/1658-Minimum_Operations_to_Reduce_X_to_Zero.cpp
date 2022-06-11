class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int right = 0;
        int left = 0;
        int max_len = -1;
        int current = 0;
        int sum = 0;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
        }
        for (right = 0; right < nums.size(); ++right) {
            current += nums[right];
            while (current > sum - x && left <= right) {
                current -= nums[left];
                left ++;
            }
            if (current == sum - x) {
                max_len = max(max_len, right - left + 1);
            }
        }
        return max_len == -1 ? -1 : nums.size() - max_len;
    }
};