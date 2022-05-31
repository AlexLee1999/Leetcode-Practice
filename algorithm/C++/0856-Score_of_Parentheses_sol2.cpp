class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> myStack;
        myStack.push(0);
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                myStack.push(0);
            } else {
                int first = myStack.top();
                myStack.pop();
                int second = myStack.top();
                myStack.pop();
                if (first == 0) {
                    myStack.push(second + 1);
                } else {
                    myStack.push(second + 2 * first);
                }
            }
        }
        return myStack.top();
    }
};