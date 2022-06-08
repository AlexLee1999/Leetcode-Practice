class Solution {
public:
    int myAtoi(string s) {
        int ptr = 0;
        while (ptr < s.size() && s[ptr] == ' ') {
            ptr ++;
        }
        int sign = 1;
        if (s[ptr] == '-') {
            sign = -1;
            ptr ++;
        }
        else if (s[ptr] == '+') {
            sign = 1;
            ptr ++;
        }
        int result = 0;
        while (ptr < s.size() && s[ptr] - '0' >= 0 && s[ptr] - '0' <= 9) {
            int digit = (s[ptr] - '0') * sign;
            if (sign == 1) {
                if ((INT_MAX / 10 < result) || (INT_MAX / 10 == result && INT_MAX % 10 < digit)) {
                    return INT_MAX;
                }
            }
            else if (sign == -1) {
                if ((INT_MIN / 10 > result) || (INT_MIN / 10 == result && INT_MIN % 10 > digit)) {
                    return INT_MIN;
                }
            }
            result *= 10;
            result += digit;
            ptr ++;
        }
        return result;
    }
};
// Time : O(n)
// Space : O(1)