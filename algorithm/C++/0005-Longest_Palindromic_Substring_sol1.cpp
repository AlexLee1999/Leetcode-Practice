class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int max_len = 1;
        for (int i=0; i<s.size() - 1; ++i) {
            findPalindrome(s, i, i, max_len, start);
            findPalindrome(s, i, i + 1, max_len, start);
        }
        return s.substr(start, max_len);
    }
    void findPalindrome(string& s, int i, int j, int& max_len, int& start) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            if (j - i + 1 > max_len) {
                max_len = j - i + 1;
                start = i;
            }
            i --;
            j ++;
        }
    }
};
// Time : O(n^2)
// Space : O(1)