class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int tmp = add(num);
            num = tmp;
        }
        return num;
    }
    int add(int num) {
        int ans = 0;
        while (num > 0) {
            ans += (num % 10);
            num /= 10;
        }
        return ans;
    }
};
// Time : O(logn)
// Space : O(logn)