class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0){
            int rem = x % 10;
            x /= 10;
            if (res > INT_MAX/10 || (res == INT_MAX / 10 && rem > 7)) {
                return 0;
            }
            if (res < INT_MIN/10 || (res == INT_MIN / 10 && rem < -8)) {
                return 0;
            }
            res = res * 10 + rem;
        }
        return res;
    }
};
// Time : O(logn)
// Space : O(1)