class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> myStack;
        myStack.push(-1);
        int ans = 0;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                myStack.push(i);
            } else {
                myStack.pop();
                if (myStack.empty()) {
                    myStack.push(i); // add a new starting point
                } else {
                    ans = max(ans, i-myStack.top());
                }
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)