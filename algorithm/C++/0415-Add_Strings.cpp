class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string s = "";
        while (i >= 0 && j >= 0) {
            int sum = (num1[i] - '0') + (num2[j] - '0') + carry;
            carry = sum / 10;
            sum %= 10;
            s = (char)(sum + '0') + s;
            i --;
            j --;
        }
        while (i >= 0) {
            int sum = (num1[i] - '0') + carry;
            carry = sum / 10;
            sum %= 10;
            s = (char)(sum + '0') + s;
            i --;
        }
        while (j >= 0) {
            int sum = (num2[j] - '0') + carry;
            carry = sum / 10;
            sum %= 10;
            s = (char)(sum + '0') + s;
            j --;
        }
        if (carry != 0) {
            s = (char)(carry + '0') + s;
        }
        return s;
    }
};
// Time : O(m + n)
// Space : O(m + n)