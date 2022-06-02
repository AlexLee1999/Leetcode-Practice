class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (t.size() == 0 && s.size() == 0) {
            return true;
        }
        if (t.size() == 0) {
            return false;
        }
        if (s.size() == 0) {
            return true;
        }
        int j = 0;
        for (int i=0; i<t.size(); ++i) {
            if (t[i] == s[j]) {
                j ++;
            }
        }
        return j == s.size();
    }
};