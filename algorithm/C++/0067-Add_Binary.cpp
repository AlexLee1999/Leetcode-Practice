class Solution {
public:
    string addBinary(string a, string b) {
        int a_ptr = a.size()-1;
        int b_ptr = b.size()-1;
        string result = "";
        int carry = 0;
        while (a_ptr >= 0 || b_ptr >= 0) {
            int sum = carry;
            if (a_ptr >= 0) {
                sum += a[a_ptr] - '0';
                a_ptr --;
            }
            if (b_ptr >= 0) {
                sum += b[b_ptr] - '0';
                b_ptr --;
            }
            carry = sum >> 1;
            result += to_string(sum & 1);
        }
        if (carry) {
            result += to_string(carry);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};