class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str = s + s;
        string substr = str.substr(1, str.size() - 2);
        if (substr.find(s) != -1) {
            return true;
        }
        return false;
    }
};