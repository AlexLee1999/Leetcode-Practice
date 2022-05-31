class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());
        int i=digits.size()-2;
        while (i >= 0 && digits[i] >= digits[i+1]) {
            i --;
        }
        if (i < 0) {
            return -1;
        } else {
            for (int j = digits.size() - 1; j > i; --j) {
                if (digits[j] > digits[i]) {
                    swap(digits[i], digits[j]);
                    reverse(digits.begin() + i + 1, digits.end());
                    break;
                }
            }
        }
        int ans = 0;
        for (int i=0; i<digits.size(); ++i) {
            if (ans <= INT_MAX - digits[i]) {
                ans += digits[i];
            } else {
                return -1;
            }
            if (i != digits.size() - 1) {
                if (ans <= INT_MAX / 10) {
                    ans *= 10;
                } else {
                    return -1;
                }
            }
        }
        return ans;
    }
};