class Solution {
public:
    int calculate(string s) {
        stack<int> myStack;
        int res = 0;
        int sign = 1;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            }
            string num = "";
            if ('0' <= s[i] && s[i] <= '9') {
                num += s[i];
                while (i + 1 < s.size() && '0' <= s[i + 1] && s[i + 1] <= '9') {
                    i ++;
                    num += s[i];
                }
                res = res + sign * stoi(num);
            }
            if (s[i] == '+') {
                sign = 1;
            }
            if (s[i] == '-') {
                sign = -1;
            }
            if (s[i] == '(') {
                myStack.push(res);
                myStack.push(sign);
                res = 0;
                sign = 1;
            }
            if (s[i] == ')') {
                int sig = myStack.top();
                myStack.pop();
                int nu = myStack.top();
                myStack.pop();
                res = res * sig + nu;
            }
        }
        return res;
    }
};
// Time : O(n)
// Space : O(n)