class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        int ans = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] > 0) {
                pos ++;
                if (neg != 0) {
                    neg ++;
                } else {
                    neg = 0;
                }
            } else if (nums[i] < 0) {
                int tmp = pos;
                if (neg > 0) {
                    pos = 1 + neg;
                } else {
                    pos = 0;
                }
                neg = 1 + tmp;
            } else {
                pos = 0;
                neg = 0;
            }
            ans = max(ans, pos);
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(1)