class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int> digits;
        int product = 1;
        int sum = 0;
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        for (int i=0; i<digits.size(); ++i) {
            product *= digits[i];
            sum += digits[i];
        }
        return product - sum;
    }
};
// Time : O(logn)
// Space : O(logn)