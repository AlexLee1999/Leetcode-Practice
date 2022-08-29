class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int operations = 0;
        while (target > startValue) {
            if ((target & 1) == 0) {
                target = target >> 1;
                operations ++;
            } else {
                target ++;
                operations ++;
            }
        }
        return operations + startValue - target;
    }
};
// Time : O(logt)
// Space : O(1)