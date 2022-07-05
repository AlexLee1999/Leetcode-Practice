class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int j = digits.size() - 1;
        int carry = 0;
        while (j >= 0) {
            int sum = digits[j] + carry;
            if (j == digits.size() - 1) {
                sum ++;
            }
            carry = sum / 10;
            sum %= 10;
            digits[j] = sum;
            j --;
        }
        
        if (carry != 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
// Time : O(n)
// Space : O(1)