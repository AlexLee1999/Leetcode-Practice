class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        int j = 0;
        while (j < str2.size()) {
            if (i == str1.size() && j < str2.size()) {
                return false;
            }
            if (nextChar(str1[i], str2[j])) {
                i ++;
                j ++;
            } else {
                i ++;
            }
        }
        return true;
    }
    bool nextChar(char a, char b) {
        if (b == 'a' && a == 'z') {
            return true;
        }
        if (b - a <= 1 && b >= a) {
            return true;
        }
        return false;
    }
};