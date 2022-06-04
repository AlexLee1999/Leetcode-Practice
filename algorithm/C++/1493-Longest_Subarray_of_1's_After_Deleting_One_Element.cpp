class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int len = 0;
        int zero_num = 0;
        for (right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                zero_num ++;
            }
            while (zero_num > 1) {
                if (nums[left] == 0) {
                    zero_num --;
                }
                left ++;
            }
            len = max(len, right - left + 1);
        }
        return len - 1;
    }
};