class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n > 0) {
            if (n == 1) {
                return true;
            }
            if (n % 3 != 0) {
                return false;
            }
            n /= 3;
        }
        return false;
    }
};
// Time : O(logn)
// Space : O(1)