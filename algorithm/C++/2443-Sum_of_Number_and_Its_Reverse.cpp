class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        bool ans = false;
        if (num <= 18) {
            ans = ans || (num % 2 == 0);
        } 
        if (num <= 198) {
            ans = ans || (num % 11 == 0);
        } 
        if (num <= 1998) {
            for (int i=0; i<=9; ++i) {
                int tmp = num - (20 * i);
                if (tmp > 0 && (tmp % 101 == 0)) {
                    return true;
                }
            }
        } 
        if (num <= 19998) {
            for (int i=0; i<=18; ++i) {
                int tmp = num - (110 * i);
                if (tmp > 0 && (tmp % 1001 == 0)) {
                    return true;
                }
            }
        } 
        for (int i=0; i<=18; ++i) {
            for (int j=0; j<=9; ++j) {
                int tmp = num - (1010 * i) - (200 * j);
                if (tmp > 0 && (tmp % 10001 == 0)) {
                    return true;
                }
            }
        }
        return ans;
    }
};
// Time : O(1)
// Space : O(1)