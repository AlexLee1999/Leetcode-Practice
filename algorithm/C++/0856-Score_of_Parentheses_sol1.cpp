class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth = 0;
        int ans = 0;
        char prev;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                depth ++;
            } else {
                depth --;
                if (prev == '(') {
                    ans += (1 << depth);
                }
            }
            prev = s[i];
        }
        return ans;
    }
};