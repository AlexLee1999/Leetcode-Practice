class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> myStack;
        for (int i=0; i<s.size(); ++i) {
            if (myStack.empty() && s[i] == ')') {
                s[i] = '$';
            } else if (s[i] == ')') {
                myStack.pop();
            } else if (s[i] == '(') {
                myStack.push(i);
            }
        }
        while (!myStack.empty()) {
            s[myStack.top()] = '$';
            myStack.pop();
        }
        s.erase(remove(s.begin(), s.end(), '$'), s.end());
        return s;
    }
};
// Time : O(n)
// Space : O(n)