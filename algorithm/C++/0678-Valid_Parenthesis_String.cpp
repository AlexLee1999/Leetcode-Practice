class Solution {
public:
    bool checkValidString(string s) {
        int max_open = 0;
        int min_open = 0;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                min_open ++;
            } else {
                min_open --;
            }
            if (s[i] != ')') {
                max_open ++;
            } else {
                max_open --;
            }
            if (max_open < 0) {
                return false;
            }
            if (min_open < 0) {
                min_open = 0;
            }
        }
        return min_open == 0;
    }
};
// Time : O(n)
// Space : O(1)