class Solution {
public:
    int removePalindromeSub(string s) {
        string old_s = s;
        reverse(s.begin(), s.end());
        if (s == old_s) {
            return 1;
        } 
        return 2;
    }
};
// Time : O(n)
// Space : O(n)