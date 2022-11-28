class Solution {
public:
    string makeGood(string s) {
        stack<char> myStack;
        for (int i=0; i<s.size(); ++i) {
            while (!myStack.empty() && i<s.size() && isUpper(myStack.top(), s[i])) {
                myStack.pop();
                i ++;
            }
            if (i<s.size()) {
                myStack.push(s[i]);
            }
        }
        string ans = "";
        while (!myStack.empty()) {
            ans += myStack.top();
            myStack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool isUpper(char a, char b) {
        if (a > b) {
            return isUpper(b, a);
        }
        if (a - 'A' < 0 || a - 'A' >= 26) {
            return false;
        }
        return b - a == 32;
    }
};
// Time : O(n)
// Space : O(n)