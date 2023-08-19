class Solution {
public:
    string kthLuckyNumber(int k) {
        int x = 2;
        int digit = 1;
        while (k - x > 0) {
            k -= x;
            x *= 2;
            digit ++;
        }
        string result = "";
        k -= 1;
        while (k > 0) {
            if (k % 2 == 1) {
                result = "7" + result;
            } else {
                result = "4" + result;
            }
            k /= 2;
        }
        int n = result.size();
        for (int i=0; i<digit - n; ++i) {
            result = "4" + result;
        }
        return result;
    }
};