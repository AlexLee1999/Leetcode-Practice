class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return check(left + 1, right, s) || check(left, right - 1, s);
            }
            left ++;
            right --;
        }
        return true;
    }
    bool check(int left, int right, string s) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left ++;
            right --;
        }
        return true;
    }
};
// Time : O(n)
// Space : O(1)