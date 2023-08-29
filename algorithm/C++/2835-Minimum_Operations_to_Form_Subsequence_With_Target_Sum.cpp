class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        unordered_map<int, int> count;
        int ans = 0;
        for (int i=0; i<nums.size(); ++i) {
            count[nums[i]] ++;
        }
        int min_digit = 32;
        for (int i=0; i<31; ++i) {
            int bit = ((target & (1 << i)) >> i);
            if (bit == 1) {
                if (count[1 << i] > 0) {
                    count[1 << i] --;
                } else {
                    min_digit = min(min_digit, i);
                }
            }
            if (count[1 << i] > 0 && min_digit < i) {
                count[1 << i] --;
                ans += (i - min_digit);
                min_digit = 32;
            }
            count[1 << (i + 1)] += (count[1 << i] / 2);
        }
        if (min_digit < 32) {
            return -1;
        } 
        return ans;
    }
};