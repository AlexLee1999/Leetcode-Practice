class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string s = countAndSay(n - 1);
        string result = "";
        char prev_char = s[0];
        int count = 1;
        for (int i=1; i<s.size(); ++i) {
            if (s[i] == prev_char) {
                count ++;
            } else {
                result += to_string(count);
                result += prev_char;
                count = 1;
                prev_char = s[i];
            }
        }
        result += to_string(count);
        result += prev_char;
        return result;
    } 
};