class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> myStack;
        for (int i=0; i<tokens.size(); ++i) {
            if (isdigit(tokens[i][0]) || (tokens[i][0] == '-' && tokens[i][1])) {
                myStack.push(stoi(tokens[i]));
            } else {
                int second = myStack.top();
                myStack.pop();
                int first = myStack.top();
                myStack.pop();
                myStack.push(calculate(first, second, tokens[i]));
            }
        }
        return myStack.top();
    }
    int calculate(int a, int b, string s) {
        if (s == "+") {
             return a + b;       
        } else if (s == "-") {
            return a - b;
        } else if (s == "*") {
            return a * b;
        } else if (s == "/") {
            return a / b;
        }
        return -1;
    }
};