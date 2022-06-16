class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int k = -1;
        for (int i = s.size() - 2; i >= 0; --i) {
            if (s[i] > s[i + 1]) {
                k = i;
            }
        }
        if (k >= 0) {
            while (k > 0 && s[k] == s[k-1]) {
                k --;
            }
            s[k] = (s[k] - '0' - 1) + '0';
            for (int j = k + 1; j < s.size(); ++j) {
                s[j] = '9';
            }
        }
        return stoi(s);
    }
};
// Time : O(n)
// Space : O(n)