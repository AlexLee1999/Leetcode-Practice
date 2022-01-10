class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) {
            return n;
        }
        int front_ptr = 0;
        int end_ptr = 1;
        int max_len = 0;
        while (end_ptr < n) {
            if (nums[end_ptr] <= nums[end_ptr - 1]) {
                front_ptr = end_ptr;
            }
            max_len = max(max_len, end_ptr - front_ptr + 1);
            end_ptr ++;
        }
        return max_len;
    }
};