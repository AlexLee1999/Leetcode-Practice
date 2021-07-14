class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x == 0) {
            return true;
        }
        long res = 0;
        int origin_x = x;
        while (x != 0) {
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        return origin_x == res;
    }
};
