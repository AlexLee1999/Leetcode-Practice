class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stackS;
        stack<char> stackT;
        
        for (int i=0; i<s.size(); ++i) {
            if (stackS.empty() && s[i] == '#') {
                continue;
            } else if (s[i] == '#') {
                stackS.pop();
            } else {
                stackS.push(s[i]);
            }
        }
        for (int i=0; i<t.size(); ++i) {
            if (stackT.empty() && t[i] == '#') {
                continue;
            } else if (t[i] == '#') {
                stackT.pop();
            } else {
                stackT.push(t[i]);
            }
        }
        return stackT == stackS;
    }
};
// Time : O(M + N)
// Space : O(M + N)