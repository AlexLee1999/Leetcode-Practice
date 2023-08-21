class Solution {
public:
    bool makePalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        int count = 0;
        while (left < right) {
            if (s[right] != s[left]) {
                count++;
            }
            if (count > 2) {
                return false;
            }
            right --;
            left ++;
        }
        return true;
    }
};