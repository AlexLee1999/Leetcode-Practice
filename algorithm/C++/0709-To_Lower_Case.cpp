class Solution {
public:
    string toLowerCase(string s) {
        for (int i=0; i<s.size(); ++i) {
            if (isUpper(s[i])) {
                s[i] = (char)(s[i] + 32);
            }
        }
        return s;
    }
    bool isUpper(char ch) {
        return ch >= 'A' && ch <= 'Z';
    }
};
// Time : O(n)
// Space : O(1)