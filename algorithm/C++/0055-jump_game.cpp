class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_step = nums[0];
        int i;
        for (i = 0; i < n && i <= max_step; ++i) {
            max_step = max(max_step, i + nums[i]);
        }
        return i == n;
    }
};
